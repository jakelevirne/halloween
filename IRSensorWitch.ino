#include <DmxMaster.h>

int sensorpin = 0;                 // analog pin used to connect the sharp sensor
float dist = 0.0;                 // variable to store the distance from sensor(initially zero)
int count = 0;						// count of times the IR path reported "broken"

// Pin 7 has a transistor connected to it
int witchTrans = 7;

float read_gp2d12_range(byte pin) {
	int tmp;

	tmp = analogRead(pin);
	if (tmp < 3)
		return -1; // invalid value

	return (6787.0 /((float)tmp - 3.0)) - 4.0;
} 

void setup()
{
  Serial.begin(9600);               // starts the serial monitor
  pinMode(witchTrans, OUTPUT); 
  DmxMaster.usePin(3);
  delay(5000);
}
 
void loop()
{
  dist = read_gp2d12_range(sensorpin);       // reads the value of the sharp sensor
  //dist = 10.0;						//just for testing.  Comment this out for real.
  Serial.println(dist);            // prints the value of the sensor to the serial monitor
  if (dist > 0.0 && dist < 100.0)
  {
  	if (count > 1) {
  		count = 0;
  		Serial.println("BOO");
  		DmxMaster.write(1,255);
  		DmxMaster.write(2,255);
  		DmxMaster.write(3,0);
  		DmxMaster.write(4,255);
  		digitalWrite(witchTrans, HIGH);
  		delay(2000);
  		digitalWrite(witchTrans, LOW);
  		delay(14000);
  		DmxMaster.write(1,0);
  		DmxMaster.write(2,0);
  		DmxMaster.write(3,0);
  		DmxMaster.write(4,0);

  	} else {
  		count += 1;
  	}
  } else {
  	count = 0;
  }
  delay(100);                    // wait for this much time before printing next value
}
