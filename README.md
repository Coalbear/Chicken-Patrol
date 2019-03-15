# Chicken-Patrol
Add monitoring and climate control to the chicken coop. 

![ChickenPatrol](Coalbear.github.com/repository/img/image.jpg)






This arduino sketch is for a ESP8266. If you have never used a ESP8266 before simply follow a guide like this one <a target="_blank" rel="noopener noreferrer" href=http://www.whatimade.today/esp8266-easiest-way-to-program-so-far/> [here] </a>. Google is your friend.

Once you are connected to the ESP8266 in the arduino IDE. Run a "blink" example to make sure everything is connected up properly. If the built in LED is flashing, then your doing great. If not, back to the google. 

Now this sketch uses a temperature sensor and 2 relays. One relay is for high temperature which will turn on a fan. The other is for low temperature which will turn on a heater. 


int tempPin = A0;
int heatPin = D0;
int fanPin = D3;

