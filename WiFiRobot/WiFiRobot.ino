// Pratik Gangwani 
// Justin Tamayo 
// 3/15/16
// ECE 4180 Lab 4; Wi-Fi controlled robot
// Robot Control via aREST + WiFi
// Skelton Code from: https://learn.adafruit.com/wifi-controlled-mobile-robot/arduino-sketch
// Github for Skeleton Code: https://github.com/openhardwarerobots/wifi-mobile-robot/tree/master/robot_wifi

// Libraries
#include <ESP8266WiFi.h>
// Accessible once ESP8266 board is added to board manager
#include <aREST.h>
// Place library from "https://github.com/marcoschwartz/aREST" into libraries folder under Arduino Folder

// Create aREST instance
aREST rest = aREST();

int labNumber;

//WiFi Parameters
const char* ssid = "NameofLAN";
const char* password = "passwordforLAN";

// The port to listen for incoming TCP connections 
#define LISTEN_PORT           80

//Create and instance of the server
WiFiServer server(LISTEN_PORT);

void setup(void)
{  
  // Start Serial to use for debugging Huzzah Board with FTDI Serial cable. 
  Serial.begin(115200);

  // Setup Digital Pins to send signal to motors and horn on mbed. 
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);

  // Expose variables and functions to aREST API. 
  rest.variable("labNumber",&labNumber);
  rest.function("forward",forward);
  rest.function("backward",backward);
  rest.function("left",left);
  rest.function("right",right);
  rest.function("stop", stop);
  rest.function("horn", horn);
  
  // Give name and ID to robot
  rest.set_id("4180");
  rest.set_name("robot");

  // Connect to Wi-Fi using WiFi library and Huzzah board
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      //Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wifi Connected!");
 
    
   // Start server
  server.begin();
  Serial.println(("Server started. Listening for connections..."));

  // Print IP Address
  Serial.println("IP address: ");
  Serial.print(WiFi.localIP());
  
}

void loop() {  

  // Set Lab Number to display on localhost webpage
  labNumber = 4;
      
  // Handle REST calls
  WiFiClient client = server.available();
  if (!client) {
   
    return;
  }
  while(!client.available()) {
    
    delay(1);
  }
  rest.handle(client);
 

}

//Movement Functions. BY setting a particular pin to high and low and listening for digital IN
// on the MBED we can trigger motor movement and make the speaker play a noise. 

// Forward
int forward(String command) {
  // Serial.println("Forward");
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(14, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  return 1;
}

// Backward
int backward(String command) {
  // Serial.println("Backward");
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(14, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  return 2;
}

// Left
int left(String command) {
  // Serial.println("Left");
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(14, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  return 3;
}

// Right
int right(String command) {
  //Serial.println("Right");
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(14, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  return 4;
}

// Stop
int stop(String command) {
  //Serial.println("Stop");
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(14, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  return 5;
}

// Horn
int horn(String command) {
  //Serial.println("Horn");
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(14, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  return 6;
}
