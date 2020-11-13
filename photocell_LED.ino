//Bird feeder

//When bird lands on the food trey.
//The Micro processor will detect the bird shadow via the Photo senor.
//The Micro processor will Turn the servo 180 degrees clockwise opening the seed latch
//The Micro processor will Turn the servo 180 degrees counter-clockwise closing the seed latch
//The Micro processor will Wait for about 5 minute before it can sense another shadow.
//So, that the same bird does get feed more than once.

#include <Servo.h>

const int sensorPin = 0;                //
const int ledPin = 9;                   //
int lightCal;                           // Intialize the Photo resistor 
int lightVal;                           // Intialize the Photo resistor Value


Servo myservo;                          // create servo object to control a servo

int pos = 0;                            // variable to store the servo position

void setup() {
  pinMode(ledPin, OUTPUT);
  lightCal = analogRead(sensorPin);
  Serial.begin(9600);                   // Read out serial  
  myservo.attach(8);                    // attaches the servo on pin 9 to the servo object
}

void loop() {
  lightVal = analogRead(sensorPin);     // Light sensor 

  // the photocell detect
  if (lightVal < lightCal - 30) {       // compare the value of the light sensor 
    digitalWrite(ledPin, HIGH);         // output to start the servo moto
   
    delay(250);
  for (pos = 0; pos <= 180; pos += 5) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);                 // tell servo to go to position in variable 'pos'
    delay(20);                          // waits 15ms for the servo to reach the position
  }
  
  for (pos = 180; pos >= 0; pos -= 5) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);                 // tell servo to go to position in variable 'pos'
    delay(20);                          // waits 1 sec for the servo to reach the position
  }
  delay(300000);                        // wait for appromiatly 5 min after the switch open and close
  }
  
  else {
    digitalWrite (ledPin, LOW);         // else if the led is low
  }
}
