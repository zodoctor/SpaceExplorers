/* This script will play a tone and
 *  blink an LED with frequecy depending
 *  on the flux incident on a photoresistor.
 * 
 */
int ledPin = 12;      // select the pin for the LED
int speakerPin = 8; // select pin for speaker output
int sensorPin = A0; // select pin for reading in photocell
double frequency = 0.; // declare variable, Hz
unsigned int periodMicroseconds = 0; // declare variable, microseconds
float sensorVal;
float scale = .1;
float offset = 0.;
int count;


void setup() {
  // declare the ledPin and speakerPin as OUTPUTs:
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  // open the serial port at 9600 bps:
  Serial.begin(9600);       
}

void loop() {
  // The snippet below is looped.  In each 
  // loop, the speakerPin and ledPin are told to go to 
  // HIGH and then LOW voltage.  They wait 
  // at HIGH or LOW for time given by
  // periodMicroseconds.  
  // Here, periodMicroseconds will be based
  // on the the light level read by the 
  // photosensor.
  // 
  sensorVal = analogRead(sensorPin);
  //Serial.print("Sensor Value:");
  //Serial.print(sensorVal);
  //Serial.print("\n");
  count = 0;
  // STUDENTS:
  frequency  = sensorVal;
  //Serial.print("frequency:");
  //Serial.print(frequency);
  //Serial.print("\n");
  // or this:
  //frequency  = scale*sensorVal+offset;

  
  periodMicroseconds = 1000000/(frequency);  
  // print out the periodMilliseconds value
  // to make sure things are working.  Click
  // the magnifying glass button in the top
  // right to see the serial output.
  //Serial.print("period (us):");
  //Serial.print(periodMicroseconds);
  //Serial.print("\n");
  
  // tell the speaker and LED pins to go HIGH
  digitalWrite(speakerPin, HIGH);
  digitalWrite(ledPin, HIGH);
  // Wait for periodMilliseconds/2
  delayMicroseconds(periodMicroseconds/2);
  
  // tell the speaker and LED pins to go LOW
  digitalWrite(speakerPin, LOW);
  digitalWrite(ledPin, LOW);
  // Wait for periodMilliseconds/2
  delayMicroseconds(periodMicroseconds/2);
  count = count+1;

}
