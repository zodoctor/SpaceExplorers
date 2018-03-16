/* Code for the "electronic trumpet.
 *  Plays different tones from a speaker
 *  depending on which combinations of 
 *  buttons are pressed.  The version here
 *  plays notes in the C major scale, but 
 *  that can easily be modified.  This 
 *  script depends on pitches.h, 
 *  which is a file that 
 *  defines the frequency of each note.
 */

#include "pitches.h"

int ledPin = 13; // choose the pin for the LED
int inPinA = 5;   // choose the input pin (for pushbutton A)
int inPinB = 6;   // choose the input pin (for pushbutton B)
int inPinC = 7;   // choose the input pin (for pushbutton C)
int speakerPin = 8;
int valA = 0;     // variable for reading the pin status
int valB = 0;     // variable for reading the pin status
int valC = 0;     // variable for reading the pin status

void setup() {
  pinMode(speakerPin,OUTPUT); // declare speaker as output
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inPinA, INPUT);    // declare pushbutton as input
  pinMode(inPinB, INPUT);    // declare pushbutton as input
  pinMode(inPinC, INPUT);    // declare pushbutton as input
}

void loop(){
  valA = digitalRead(inPinA);  // read input value on Yellow button 
  valB = digitalRead(inPinB);  // read input value on Yellow button
  valC = digitalRead(inPinC);  // read input value on Yellow button
  if ((valA == HIGH) and (valB == HIGH) and (valC == HIGH)){         // check if the input is HIGH (button released)
    noTone(speakerPin);  // turn sound off
  } 
  else if ((valA == HIGH) and (valB == HIGH) and (valC == LOW)) // C pressed
  {
    // Here the 'tone' function is used.  The inputs to
    // tone are the pin number on which you want to output
    // the sound, the frequency of the note, and the length
    // of time in milliseconds to play the tone, respectively
    tone(speakerPin,NOTE_C5,20);  // turn sound on
  }
  else if ((valA == HIGH) and (valB == LOW) and (valC == HIGH)) // B pressed
  {
    tone(speakerPin,NOTE_D5,20);  // turn sound on
  }
  // STUDENTS fill in the remaining if/thens
  else if ((valA == LOW) and (valB == HIGH) and (valC == HIGH)) // A pressed
  {
    tone(speakerPin,NOTE_E5,20);  // turn sound on
  }
  else if ((valA == HIGH) and (valB == LOW) and (valC == LOW)) // B and C pressed
  {
    tone(speakerPin,NOTE_F5,20);  // turn sound on
  }
  else if ((valA == LOW) and (valB == LOW) and (valC == HIGH)) // A and B pressed
  {
    tone(speakerPin,NOTE_G5,20);  // turn sound on
  }
  else if ((valA == LOW) and (valB == HIGH) and (valC == LOW)) // A and C pressed
  {
    tone(speakerPin,NOTE_A5,20);  // turn sound on
  }
  else if ((valA == LOW) and (valB == LOW) and (valC == LOW)) // all pressed
  {
    tone(speakerPin,NOTE_B5,20);  // turn sound on
  }
  else {
    noTone(speakerPin);  // turn sound off
  }
}
