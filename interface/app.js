// Pratik Gangwani 
// Justin Tamayo 
// 3/15/16
// ECE 4180 Lab 4; Wi-Fi controlled robot
// Main app javascript file to run localhost client
// Skeleton code from: https://learn.adafruit.com/wifi-controlled-mobile-robot/building-the-web-interface
// Github for skeleton code: https://github.com/openhardwarerobots/wifi-mobile-robot/tree/master/interface


// Set up Express Module
var express = require('express');
var app = express();

// Define localhost port
var port = 3000;

// Set view engine to jade
app.set('view engine', 'jade');

// Set public folder
app.use(express.static(__dirname + '/public'));

// Serve interface
app.get('/', function(req, res){
  res.render('interface');
});

// Utilize aRest API access server
var arest = require("arest")(app);

//Add your server as an aREST device
arest.addDevice('http','YourServerIPAddress');

// Start server
app.listen(port);
console.log("Listening on port " + port);
