int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
float sensorValue = 0;  // variable to store the value coming from the first photoresistor
float sensor2Value = 0; // variable to store the value coming from the 2nd photoresistor
float threshold = 0;
int speakerPin = 10;
float frequency = 0;
float periodMicroseconds = 0;
int sensor2Pin = A1;
float dutycycle = .5;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  // open the serial port at 9600 bps:
  Serial.begin(9600);       
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  frequency = 3*sensorValue - 400; // you may want to adjust this formula
  periodMicroseconds = 1000000/frequency;
  sensor2Value = analogRead(sensor2Pin);
  // change the duty cycle below by making it
  // depend on sensor2Value.  This way changing the 
  // light on the second light sensor will change the 
  // duty cycle 
  dutycycle = .5;
  Serial.print(sensor2Value);
  Serial.print("\t");
  // use the sensorValue to determine how
  // long between the speaker going back
  // and forth:  
  digitalWrite(speakerPin, HIGH);
  delayMicroseconds(periodMicroseconds*dutycycle);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(periodMicroseconds*(1-dutycycle));

}
