//How it's wired:
//Single relay (Songle) as the switch for simplicity, given the motor in the witch
//DMX adapter wired to the round LED canister
//DIP settings 1ON, 2-9OFF, 10ON
//Using 9V, 1A power supply
//HC-SR501 PIR sensor (half covered in electrical tape, and nobs adjusted)
//https://www.mpja.com/download/31227sc.pdf

#include <DmxMaster.h>

int sensorpin = 0;                 // analog pin used to connect the PIR sensor
float dist = 0.0;                 // variable to store the distance from sensor(initially zero)
int count = 0;						// count of times the IR path reported "broken"

// Pin 7 has a relay connected to it
int witchRelay = 7;
// Pin 8 is connected to the ThunderDuino (A0).  When it goes LOW, thunder claps.
int thunderPin = 8;

void setup()
{
  Serial.begin(9600);               // starts the serial monitor
  pinMode(witchRelay, OUTPUT); 
  pinMode(thunderPin, OUTPUT);
  digitalWrite(witchRelay, LOW);
  digitalWrite(thunderPin, HIGH);
  DmxMaster.usePin(3);
  delay(5000);
}
 
void loop()
{
  dist = analogRead(sensorpin);       // reads the value of the PIR sensor

  Serial.println(dist);            // prints the value of the sensor to the serial monitor
  if (dist > 600.0)
  {
  	if (count > 0) {
  		count = 0;
  		Serial.println("BOO");

  		digitalWrite(witchRelay, HIGH);
  		digitalWrite(thunderPin, LOW);
  		FlashDMX(255,255,0,255,300,200);
  		FlashDMX(255,255,255,255,200,100);
  		FlashDMX(255,255,255,255,600,300);
  		digitalWrite(thunderPin, HIGH);
  		delay(18000);
  		digitalWrite(witchRelay, LOW);


  	} else {
  		count += 1;
  	}
  } else {
  	count = 0;
  }
  delay(1000);                    // wait for this much time before printing next value
}

void FlashDMX(int c1, int c2, int c3, int c4, int delayOn, int delayOff)
{
   	DmxMaster.write(1,c1);
  	DmxMaster.write(2,c2);
 	DmxMaster.write(3,c3);
  	DmxMaster.write(4,c4);
  	delay(delayOn);
  	DmxMaster.write(1,0);
  	DmxMaster.write(2,0);
  	DmxMaster.write(3,0);
  	DmxMaster.write(4,0);
  	delay(delayOff);
}
