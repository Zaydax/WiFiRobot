// Pratik Gangwani 
// Justin Tamayo 
// 3/15/16
// ECE 4180 Lab 4; Wi-Fi controlled robot
// Javascript file to define the funcitonality of the interface that will be shown on the localhost webpage client
// Skeleton code from: https://learn.adafruit.com/wifi-controlled-mobile-robot/building-the-web-interface
// Github for skeleton code: https://github.com/openhardwarerobots/wifi-mobile-robot/tree/master/interface

// Function to get labNumber and connection status from Arduino
setInterval(function() {

    $.get('/robot/labNumber', function( json_data ) {
        if (json_data.labNumber){
            $("#labNumber").html("ECE 4180 Lab " + json_data.labNumber);    
        }
        if (json_data.connected == 1){
            $("#wifiStatus").html("Online");
            $("#wifiStatus").css("color","green");    
        }
        else {
            $("#wifiStatus").html("Offline");
            $("#wifiStatus").css("color","red");     
        }
    })
    .fail(function() {
       $("#wifiStatus").html("Offline");
       $("#wifiStatus").css("color","red");      
    });

}, 1000);

// Function to control Motor's and LED's and Speaker on the Robot
// Note the use of the mousedown and mouseup functions. This gives the user
// precise control over robot movement. Right/Left turning happen in place. 
$(document).ready(function() {

  $("#1")
    .mousedown(function() {
      $.get('/robot/forward');     
  })
    .mouseup(function() {
      $.get('/robot/stop');     
  });
  
  $("#2")
    .mousedown(function() {
      $.get('/robot/left');     
  })
    .mouseup(function() {
      $.get('/robot/stop');     
  });

  $("#3")
    .mousedown(function() {
      $.get('/robot/right');     
  })
    .mouseup(function() {
      $.get('/robot/stop');     
  });

  $("#4")
    .mousedown(function() {
      $.get('/robot/backward');     
  })
    .mouseup(function() {
      $.get('/robot/stop');     
  });

  $("#5")
    .mousedown(function() {
      $.get('/robot/horn');     
  })
    .mouseup(function() {
      $.get('/robot/stop');     
  });
});