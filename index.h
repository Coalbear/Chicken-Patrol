const char MAIN_page[] PROGMEM = R"=====(
<html>
	<head>
    <script>
      function refreshIFrame() {
        var x = document.getElementById("statusbox");
        x.contentWindow.location.reload();
        var t = setTimeout(refreshIFrame, 3000);
      }
    </script>
		<title>Hen Hut</title>
		<meta charset="utf-8" />
		<meta http-equiv="Content-type" content="text/html; charset=utf-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1" />
		<style type="text/css">
   *{
    margin: 0;
    padding: 0;
    }
		body {
        background-color: #5d5d61;
        margin: 0px;
        padding: 0px;
        color: #323232;
        font-family: Verdana;
        font-size: 16px;
        line-height:1em; 
        width: 100%;
        height: 100%;
        background-image: url("https://previews.123rf.com/images/ezhevica/ezhevica1803/ezhevica180300020/96920158-vector-seamless-pattern-with-hand-drawn-chickens-beautiful-ink-drawing-heavy-contour-abstract-design.jpg");
        background-repeat: repeat; 
        background-attachment: fixed;  
        background-size: 200px 200px;      
    } 
    #title  {
        margin-bottom: 10px;
    }
		#bluebubble {
			width: 600px;
			margin: 0em auto;
			padding: 50px;
			background-color: #778aa6;
			border-radius: 1em;
		}
		#statusbox {
			width: 100%;
			height: 100;
			margin: 0 auto;
			background-color: #b7bbc3;
			frameBorder="0"
			display: inline-block;
		}
		a:link, a:visited {
			color: #38488f;
			text-decoration: none;
			font-weight:bold;
		}
    @media (max-width: 700px) {
        body {
            background-color: #fff;
        }
        div {
            width: auto;
            margin: 0 auto;
            border-radius: 0;
            padding: 1em;
        }
    }
    
		</style>    
	</head>
	<body onload="refreshIFrame()">
		<div id="bluebubble">
			<h2 id="title">Chicken Monitoring System</h2>
  			<p>Auto Comfort: <a href="enabled" target="myIframe">Enabled</a> , <a href="disabled" target="myIframe">Disable all</a><br></p>
      <div style="border-radius: 10px; width: 600px; overflow: hidden;">  
  			<p><iframe id="statusbox" name="myIframe"><br> 
      </div>
		</div>
	</body>
</html>
)=====";
