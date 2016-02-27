int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int threshold = 0;
int speakerPin = 10;
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
  Serial.print(sensorValue);
  Serial.print("\t");
  // use the sensorValue to determine how
  // long between the speaker going back
  // and forth:  
  digitalWrite(speakerPin, HIGH);
  delayMicroseconds(sensorValue);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(sensorValue);
  // Challenge: change what is in the 
  // delayMicroseconds commands above so that the
  // minimum frequency you speaker plays is
  // 200 Hz and the maximum is 2 kHz.

  // Hint: Notice that the sensorVal that is being
  // printed in that window has a minimum of ~200 
  // when there is lots of light and max of ~800 when
  // there is no light.  We want to turn numbers between
  // 200 and 800 into numbers between 200 and 2000.  
  // Can you write a math equation that can do this?
  // Hint 2: You may need to use the slope formula and 
  // find a y-intercept Once you have that formula
  // you'll need to change from frequency to period
  // since delayMicroseconds will delay for the 
  // period you specify before moving the speaker
  // with digitalWrite
}
