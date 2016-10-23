//How it's wired:
//Two transistors- one for reaper and one for pneumatic solenoid (4V210-N08-DC12V-W)
//Solenoid positive (+) wired to Vin, using 12V, 1.5A power adapter (labelled DVE)
//Solenoid transistor is S8050; 470 ohm resistor (yellow, purple, brown, gold) to base
//Reaper transistor is 2N3904 (https://www.sparkfun.com/datasheets/Components/2N3904.pdf)
//Reaper transistor has 1kOhm resistor (brown, black, red, gold) to the base


int sensorpin1 = 0;                 // analog pin used to connect the PIR sensor
float dist1 = 0.0;                 // variable to store the distance from sensor(initially zero)
int sensorpin2 = 1;                 // analog pin used to connect the PIR sensor
float dist2 = 0.0;                 // variable to store the distance from sensor(initially zero)

int lastSensorSeen = 1;

// Pin 7 has a transistor connected to it
int ghostTrans = 7;
//Pin 8 has the solenoid
int solTrans = 8;


void setup()
{
  pinMode(ghostTrans, OUTPUT); 
  digitalWrite(ghostTrans, LOW);
  pinMode(solTrans, OUTPUT); 
  digitalWrite(solTrans, LOW);
  Serial.begin(9600);               // starts the serial monitor
  delay(5000);
}
 
void loop()
{
  dist1 = analogRead(sensorpin1);       // reads the value of the sharp sensor
  dist2 = analogRead(sensorpin2);
  Serial.print("S1:");
  Serial.println(dist1);            // prints the value of the sensor to the serial monitor
  Serial.print("S2:");
  Serial.println(dist2);            // prints the value of the sensor to the serial monitor

  if (dist2 > 600.0) {
  	lastSensorSeen = 2;
  }

  if (dist1 > 600.0)
  {
  	if (lastSensorSeen == 2) {
  		Serial.println("BOO");
  		digitalWrite(ghostTrans, HIGH);
  		digitalWrite(solTrans, HIGH);
  		delay(3000);
  		digitalWrite(ghostTrans, LOW);
  		delay(12000);
  		digitalWrite(solTrans, LOW);
  	}
  	lastSensorSeen = 1;
  }
  delay(1000);                    // wait for this much time before printing next value
}
