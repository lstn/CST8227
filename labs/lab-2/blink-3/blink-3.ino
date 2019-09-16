/* LED Blink, Teensyduino Tutorial #1
   http://www.pjrc.com/teensy/tutorial.html
 
   This example code is in the public domain.
*/

// Teensy 2.0 has the LED on pin 11
// Teensy++ 2.0 has the LED on pin 6
// Teensy 3.x / Teensy LC have the LED on pin 13
const int ledPin = 20;
const int buttonPin = 9;
int buttonState = false;

// the setup() method runs once, when the sketch starts

void setup() {
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

// the loop() methor runs over and over again,
// as long as the board has power

void loop() {
  if (digitalRead(buttonPin) == true) {
    buttonState = !buttonState;
    digitalWrite(ledPin, buttonState);
  } while (digitalRead(buttonPin) == true) {
    delay(50);
  }
}
