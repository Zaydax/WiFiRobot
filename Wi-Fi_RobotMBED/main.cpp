// Pratik Gangwani 
// Justin Tamayo 
// 3/15/16
// ECE 4180 Lab 4; Wi-Fi controlled robot
// C File to run MBEd anc control motor, LED, and speaker functions by reading in digital signals from Huzzah 8266 board

#include "mbed.h"
#include "Motor.h"
#include "Speaker.h"

//Define MBED LED's for use
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);

// Define Digital Pins to read in digital signals from Huzzah 8266 board
DigitalIn forward(p30);
DigitalIn backward(p29);
DigitalIn left(p28);
DigitalIn right(p27);
DigitalIn horn(p26);

// Define Motor pins to connect to H-Bridge
Motor rightMotor(p21, p16, p15); // pwm, fwd, rev
Motor leftMotor(p22, p19, p17); // pwm, fwd, rev

// Define Speaker pin (MUST BE PIN 18, ANALOG OUT for use with Speaker.h!)
Speaker mySpeaker(p18);

int main() {

// Loop forever
// Check to see if a pin is high. If that pin is high, execute that pin for as long as the signal is high on that pin. 
// When you let go on the mouse click the code defaults to doing nothing
// Each pin moves the robot in a particular direction, and activates a specific LED
// Horn will not run forever if you hold it down, it is simply a click
// Setting speed to 0.5 on the motors saves a lot of battery power

    while(1){
        
        if(forward) {
            rightMotor.speed(0.5);
            leftMotor.speed(0.5);
            myled1 = 1;
            myled2 = 0;
            myled3 = 0;
            myled4 = 0;
        } else if(backward) {
            rightMotor.speed(-0.5);
            leftMotor.speed(-0.5);
            myled1 = 0;
            myled2 = 1;
            myled3 = 0;
            myled4 = 0;
        } else if(left) {
            rightMotor.speed(0.5);
            leftMotor.speed(-0.5);
            myled1 = 0;
            myled2 = 0;
            myled3 = 1;
            myled4 = 0;
        } else if(right) {
            rightMotor.speed(-0.5);
            leftMotor.speed(0.5);
            myled1 = 0;
            myled2 = 0;
            myled3 = 0;
            myled4 = 1;
        } else if(horn) {
            rightMotor.speed(0.0);
            leftMotor.speed(0.0);
            myled1 = 1;
            myled2 = 1;
            myled3 = 1;
            myled4 = 1;
            mySpeaker.PlayNote(440.0, 0.5, 0.5);
        } else {
            rightMotor.speed(0.0);
            leftMotor.speed(0.0);
            myled1 = 0;
            myled2 = 0;
            myled3 = 0;
            myled4 = 0;
        }
    }
}
