//How it's wired:
//2N3904 (https://www.sparkfun.com/datasheets/Components/2N3904.pdf) transistor as the switch
//47k-ohm resistor to the base
//LED strip wired directly to ghostLED digital out
//Using 9V, 1A power supply
//HC-SR501 PIR sensor (half covered in electrical tape, and nobs adjusted)
//https://www.mpja.com/download/31227sc.pdf


int sensorpin = 0;                 // analog pin used to connect the sharp sensor
float dist = 0.0;                 // variable to store the distance from sensor(initially zero)
int count = 0;						// count of times the IR path reported "broken"

// Pin 7 has a transistor connected to it
int ghostTrans = 7;

// Pin 8 has an LED connected to it
int ghostLED = 8;



void setup()
{
  Serial.begin(9600);               // starts the serial monitor
  pinMode(ghostTrans, OUTPUT); 
  pinMode(ghostLED, OUTPUT);
  delay(5000);
}
 
void loop()
{
  dist = analogRead(sensorpin);       // reads the value of the sharp sensor
  //dist = 10.0;
  Serial.println(dist);            // prints the value of the sensor to the serial monitor
  if (dist > 600.0)
  {

  		Serial.println("BOO");
  		digitalWrite(ghostTrans, HIGH);
  		digitalWrite(ghostLED, HIGH);
  		delay(15000);
  		digitalWrite(ghostLED, LOW);
  		digitalWrite(ghostTrans, LOW);
  }
  delay(1000);                    // wait for this much time before printing next value
}
