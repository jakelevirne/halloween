/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int whiteButtonPin = 2;     // the number of the white pushbutton pin
const int blueButtonPin = 3;     // the number of the white pushbutton pin
const int doorPin =  7;      // the number of the coffin door transistor base pin
const int reaperPin =  8;      // the number of the reaper transistor base pin
const int sensorpin1 = 0;                 // analog pin used to connect the PIR sensor

float dist1 = 0.0;                 // variable to store the distance from sensor(initially zero)

// variables will change:
int whiteButtonState = 0;         // variable for reading the white pushbutton status
int blueButtonState = 0;         // variable for reading the blue pushbutton status

void setup() {
  // initialize the door and reaper pins as an output:
  pinMode(doorPin, OUTPUT);
  pinMode(reaperPin, OUTPUT);  
  // initialize the pushbutton pins as an input:
  pinMode(whiteButtonPin, INPUT);
  pinMode(blueButtonPin, INPUT);
  
  Serial.begin(9600);               // starts the serial monitor
  delay(3000);
}

void loop() {
    
  dist1 = analogRead(sensorpin1);       // reads the value of the sharp sensor
  Serial.print("S1:");
  Serial.println(dist1);            // prints the value of the sensor to the serial monitor
 
  if (dist1 > 500.0)
  {
  	Serial.println("BOO");

  	digitalWrite(doorPin, HIGH);
  	delay(300);
  	digitalWrite(doorPin, LOW);
  	delay(500);

  	digitalWrite(doorPin, HIGH);
  	delay(300);
  	digitalWrite(doorPin, LOW);
  	delay(500);

  	digitalWrite(doorPin, HIGH);
  	delay(300);
  	digitalWrite(doorPin, LOW);
  	delay(700);

  	digitalWrite(doorPin, HIGH);
  	delay(300);
  	digitalWrite(doorPin, LOW);
  	delay(500);

  	digitalWrite(doorPin, HIGH);
  	delay(300);
  	digitalWrite(doorPin, LOW);
  	delay(500);

  	digitalWrite(doorPin, HIGH);
  	delay(00);
  	digitalWrite(doorPin, LOW);
  	delay(500);
  	delay(5000);

  	digitalWrite(doorPin, HIGH);
  	digitalWrite(reaperPin, HIGH);
  	delay(1000);
  	digitalWrite(reaperPin, LOW);
  	delay(13000);
  	digitalWrite(doorPin, LOW);
  }
  
  // read the state of the pushbutton values:
  whiteButtonState = digitalRead(whiteButtonPin);
  blueButtonState = digitalRead(blueButtonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (blueButtonState == HIGH) {
    // turn coffin door and reaper on:
    digitalWrite(doorPin, HIGH);
    digitalWrite(reaperPin, HIGH);
  } else if (whiteButtonState == HIGH) {
    // turn coffin door on and reaper off:
    digitalWrite(doorPin, HIGH);
    digitalWrite(reaperPin, LOW);
  } else {
    // turn coffin door and reaper off:
    digitalWrite(doorPin, LOW);
    digitalWrite(reaperPin, LOW);

  }
}
