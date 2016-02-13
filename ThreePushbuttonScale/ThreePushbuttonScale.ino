/* Basic Digital Read
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13, when pressing a pushbutton attached to pin 7. It illustrates the
 * concept of Active-Low, which consists in connecting buttons using a
 * 1K to 10K pull-up resistor.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */

#include "pitches.h"

int ledPin = 13; // choose the pin for the LED
int inPinY = 5;   // choose the input pin (for a pushbutton)
int inPinW = 6;   // choose the input pin (for a pushbutton)
int inPinB = 7;   // choose the input pin (for a pushbutton)
int speakerPin = 8;
int valY = 0;     // variable for reading the pin status
int valB = 0;     // variable for reading the pin status
int valW = 0;     // variable for reading the pin status

void setup() {
  pinMode(speakerPin,OUTPUT); // declare speaker as output
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inPinY, INPUT);    // declare pushbutton as input
  pinMode(inPinW, INPUT);    // declare pushbutton as input
  pinMode(inPinB, INPUT);    // declare pushbutton as input
}

void loop(){
  valY = digitalRead(inPinY);  // read input value on Yellow button 
  valW = digitalRead(inPinW);  // read input value on Yellow button
  valB = digitalRead(inPinB);  // read input value on Yellow button
  if ((valY == HIGH) and (valW == HIGH) and (valB == HIGH)){         // check if the input is HIGH (button released)
    noTone(speakerPin);  // turn sound off
  } 
  else if ((valY == HIGH) and (valW == HIGH) and (valB == LOW)) // Black pressed
  {
    tone(speakerPin,NOTE_C5,20);  // turn sound on
  }
  else if ((valY == HIGH) and (valW == LOW) and (valB == HIGH)) // White pressed
  {
    tone(speakerPin,NOTE_D5,20);  // turn sound on
  }
  else if ((valY == LOW) and (valW == HIGH) and (valB == HIGH)) // Yellow pressed
  {
    tone(speakerPin,NOTE_E5,20);  // turn sound on
  }
  else if ((valY == HIGH) and (valW == LOW) and (valB == LOW)) // Black and White pressed
  {
    tone(speakerPin,NOTE_F5,20);  // turn sound on
  }
  else if ((valY == LOW) and (valW == LOW) and (valB == HIGH)) // White and Yellow pressed
  {
    tone(speakerPin,NOTE_G5,20);  // turn sound on
  }
  else if ((valY == LOW) and (valW == HIGH) and (valB == LOW)) // black and yellow pressed
  {
    tone(speakerPin,NOTE_A5,20);  // turn sound on
  }
  else if ((valY == LOW) and (valW == LOW) and (valB == LOW)) // all pressed
  {
    tone(speakerPin,NOTE_B5,20);  // turn sound on
  }
  else {
    noTone(speakerPin);  // turn sound on
  }
}
