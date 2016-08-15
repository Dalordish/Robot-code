// PIN LIST
// MOTORS
// DIGITAL
// 13,12
// 11,10
//  9,8

//GND ECHO TRIG VCC
//PINK YELLOW ORANGE RED
// IRS

//Ultrasonics
//52,53
//ECHO TRIG
//50,51

// 48,49

//LINE FOLLOWERS

//int trig = 50; // attach pin 3 to Trig
//int echo = 51; //attach pin 4 to Echo

#include "RB_Movement.h"
#include "RB_Motor.h"


int btnPin = 24;
bool pressed = 0;
bool state = 0;

Movement bot(13, 12, 11, 10, 9, 8); //this creates an instance of the object and sets motor pins

void setup() { //nothing is needed in setup
  pinMode(btnPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  pressed = !digitalRead(btnPin);
  if (pressed == 0) {
    bot.allStop(); //stop the robot
  }
  else {
    state = !state;
    Serial.println("yes");
    delay(100);
  }

  if (state == 1) {
    bot.manualMotors(1,50,10); //drive the motors with comma seperated values
    delay(100);
    Serial.println("on!");
  }
  else {

  }
  Serial.println(pressed);
  
  // delay(1000);
  // bot.allStop(); //stop the robot
  // delay(1000);
  // bot.moveStraight(180,100); //move backwards at full speed
  // delay(1000);
  // bot.moveStraight(0,0); //another way of stopping the robot
  // delay(1000);
}
