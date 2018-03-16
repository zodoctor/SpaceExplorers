
/* This script blinks an LED and 
/* plays a tone, both at the same 
/* frequency.  The frequency is specified
 * below.  This also has the added functionality
 * that it can go to frequencies higher than 200 hz
 */
int ledPin = 12;      // select the pin for the LED
int speakerPin = 8; // select pin for speaker output
double frequency = 2000.; // declare variable, Hz
unsigned int periodMilliseconds = 0; // declare variable, milliseconds
unsigned long periodMicroseconds = 0; // variable, microseconds
void setup() {
  // declare the ledPin and speakerPin as OUTPUTs:
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  // open the serial port at 9600 bps:
  Serial.begin(9600);       
}

void loop() {
  // The snippet below is looped.  In each 
  // loop, the speakerPin and ledPin are told to go to 
  // HIGH and then LOW voltage.  They wait 
  // at HIGH or LOW for time given by
  // periodMicroseconds.  
  
  // STUDENTS:
  if (frequency < 200.){
  periodMilliseconds = 1000/frequency;
  
  // tell the speaker and LED pins to go HIGH
  digitalWrite(speakerPin, HIGH);
  digitalWrite(ledPin, HIGH);

  // STUDENTS
  delay(periodMilliseconds/2);
  
  // tell the speaker and LED pins to go LOW
  digitalWrite(speakerPin, LOW);
  digitalWrite(ledPin, LOW);
  // Wait for periodMilliseconds/2
  // STUDENTS
  delay(periodMilliseconds/2);}

  // now add code for higher frequency:
  else{
  periodMicroseconds = 1000000/frequency;
  
  // tell the speaker and LED pins to go HIGH
  digitalWrite(speakerPin, HIGH);
  digitalWrite(ledPin, HIGH);

  // STUDENTS
  delayMicroseconds(periodMicroseconds/2);
  
  // tell the speaker and LED pins to go LOW
  digitalWrite(speakerPin, LOW);
  digitalWrite(ledPin, LOW);
  // Wait for periodMicroseconds/2
  // STUDENTS
  delayMicroseconds(periodMicroseconds/2);}

}
