//===============================================================
// Libraries and Variables
//===============================================================
#include "ESP8266WiFi.h"
#include "WiFiClient.h"
#include "ESP8266WebServer.h"
#include "index.h" //custom webpage here, put in same folder as this sketch

IPAddress ip(192, 168, 0, 100); //set static ip
IPAddress gateway(192, 168, 0, 1); //set getteway
IPAddress subnet(255, 255, 255, 0);//set subnet

String display_line1 = ""; //Line One of Iframe
String display_line2 = ""; //Line two of Iframe
String display_line3 = ""; // Line three of Iframe
float temp = 0;
String displayString = "";
int tempPin = A0;
int heatPin = D0;
int fanPin = D3;
int heat_temp = 0;
int cool_temp = 30;
int loop_delay = 60;
int current_loop = 0;
bool AUTO = false;

const char* ssid = "dlink-9398";
const char* password = "cyivw30042";
 
ESP8266WebServer server(80); //Starts webserver. 

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
/* 

The first function handleRoot() is the home page. It is setting
the index string to MAIN_page which is defined in index.hThe second
function handleenable() sets the Autocomfort enable, which returns
the display string to the iframe on the html page. The third function
handledisable() turns all outputs off, disables auto and returns a
string "Auto comfort disabled".

*/
void handleRoot() {
 Serial.println(" You called root page");
 String index = MAIN_page; //Read HTML contents
 server.send(200, "text/html", index); //Send web page
}

void handleenable() { 
 Serial.println(" Autocomfort enabled page");
 AUTO = true;
 server.send(200, "text/html", displayString);
}

void handledisable() { 
 Serial.println(" Autocomfort disabled page");
 digitalWrite(heatPin,LOW);
 digitalWrite(fanPin,LOW);
 AUTO = false;
 server.send(200, "text/html", "Auto comfort disabled");
}

//==============================================================
//                  SETUP
//==============================================================

void setup(void){
  pinMode(tempPin, INPUT);
  pinMode(heatPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  digitalWrite(heatPin, LOW);
  digitalWrite(fanPin, LOW);
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }
  Serial.println("");
  Serial.println("Connected to ");
  Serial.println(ssid);
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/enabled", handleenable);
  server.on("/disabled", handledisable);
  server.begin();
  Serial.println("Web server started!");
}

//===============================================================
// Main Loop
//===============================================================

void loop(void){
  display_line1 = "";
  temp = (analogRead(A0) * 330.0) / 1023.0;
  Serial.println(" Temperature: ");
  Serial.println(temp);
  Serial.println("°C");
  display_line1 += (" Temperature: ");
  display_line1 += (temp);
  display_line1 += ("°C <br>");
  current_loop = current_loop +1;
  Serial.println(current_loop);


  if (current_loop == loop_delay){
    if (AUTO == true){
      if (temp < heat_temp){
        digitalWrite(heatPin, HIGH);
        Serial.println(" Heater turned on \n");
        display_line2 = (" Heater turned on <br>"); 
      }
      if (temp > heat_temp) {
        digitalWrite(heatPin, LOW);
        Serial.println(" Heater turned off \n");
        display_line2 = (" Heater turned off <br>");
      }
      if (temp > cool_temp){
        digitalWrite(fanPin, HIGH);
        Serial.println(" Fan turned on \n");
        display_line3 = (" Fan turned on <br>");
      }
      if (temp < cool_temp){
        digitalWrite(fanPin, LOW);
        Serial.println(" Fan turned off \n");
        display_line3 = (" Fan turned off <br>");
      }
      }
     displayString = "";
     displayString += display_line1;
     displayString += display_line2;
     displayString += display_line3;
     current_loop = 0;
     }  
  server.handleClient();
  delay(100);
}
