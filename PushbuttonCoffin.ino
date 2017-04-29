/*

This is for controlling the coffin and reaper props.  The effect is to cause the coffin door to
bang and then for the coffin door to swing open and allow the reaper to fall forward as it plays
its startle sound.

The coffin is controlled using pneumatics and a solenoid that is tripped using a transistor.  
The reaper is controlled by a transistor acting as a switch, connected to the "demo" jack of the reaper. 

The entire setup is meant to be controlled in two ways:
-manually using two push-buttons (one for banging the door, and one for opening the door and 
triggering the reaper startle).
-or automatically tripped by the victim passing by the PIR sensor set several feet ahead of the prop

How it's wired:
Two transistors- one for reaper and one for pneumatic solenoid (4V210-N08-DC12V-W)
Solenoid positive (+) wired to Vin, using 12V, 1.5A power adapter (labelled DVE)
Solenoid transistor is S8050; 470 ohm resistor (yellow, purple, brown, gold) to base
Reaper transistor is 2N3904 (https://www.sparkfun.com/datasheets/Components/2N3904.pdf)
Reaper transistor has 1kOhm resistor (brown, black, red, gold) to the base
 */

// constants won't change. They're used here to
// set pin numbers:
const int whiteButtonPin = 2;     // the number of the white pushbutton pin
const int blueButtonPin = 3;     // the number of the blue pushbutton pin
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
