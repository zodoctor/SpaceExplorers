int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
float threshold = 0;
void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  // open the serial port at 9600 bps:
  Serial.begin(9600);       
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.print(sensorValue);
  Serial.print("\t");
  // Once you've loaded your code on the board,
  // click the magnifying glass in the top right 
  // corner of this window.  Another window will come
  // up showing some changing numbers.  How do the 
  // numbers change depending on the amount of light 
  // on the photocell? Now let's turn those numbers
  // into a "threshold" that controls if an LED is
  // on or off.  That is, *if* the number in the
  // window is greater than a certain number, turn the 
  // Arduino LED on, otherwise turn it off.  Add your own
  // code below which does this.  Look at the following
  // web pages to learn how to turn the LED on and off and
  // how to use if-then statements. Ask the instructor
  // if you need help, but don't be afraid to try things
  // with the code yourself!  These things almost never
  // work the first time. They take trial and error!
}
