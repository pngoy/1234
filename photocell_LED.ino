//https://create.arduino.cc/projecthub/55546/innovation-lab-7-photocell-led-on-off-3df0ab
//11.12.2020

//www.elegoo.com
//2016.12.08

#include <Servo.h>

const int sensorPin = 0;
const int ledPin = 9;
int lightCal;
int lightVal;


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(ledPin, OUTPUT);
  lightCal = analogRead(sensorPin);
  Serial.begin(9600);
  myservo.attach(8);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  lightVal = analogRead(sensorPin);

  // the photocell detect
  if (lightVal < lightCal - 30) {
    digitalWrite(ledPin, HIGH);  
   
    delay(1000);
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
  
  else {
    digitalWrite (ledPin, LOW);
  }
}
