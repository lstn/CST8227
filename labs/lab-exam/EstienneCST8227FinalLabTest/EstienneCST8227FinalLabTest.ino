#include <Bounce.h>

int dataPin = 14;
int latchPin = 15;
int clockPin = 16;
int btnPin = 9;
Bounce pushbutton = Bounce(btnPin, 10);  // 10 ms debounce

unsigned int count = 0; 

byte sevenSegmentDisplay[10] = {511, // off
                                127, // A
                                191, // B
                                223, // C
                                239, // D
                                247, // E
                                251, // F
                                253, // G
                                254, // .
                                256}; // 8.
String serialOutput[10] = {"PBS press # 1 => Segment A",
                           "PBS press # 2 => Segment B",
                           "PBS press # 3 => Segment C",
                           "PBS press # 4 => Segment D",
                           "PBS press # 5 => Segment E",
                           "PBS press # 6 => Segment F",
                           "PBS press # 7 => Segment G",
                           "PBS press # 8 => Segment Decimal Point",
                           "PBS press # 9 => 8.",
                           "PBS press # 10 => all segments OFF"};

void setup() 
{
  // initialize I/O pins
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT); 
  pinMode(btnPin, INPUT);

  digitalWrite(dataPin, 0);
  digitalWrite(latchPin, 0);
  digitalWrite(clockPin, 0);
  
}
 
void loop() 
{
  if (pushbutton.update()) {
    if (pushbutton.fallingEdge()) {
      // output message to serial
      Serial.println(serialOutput[count%10]);
      // increment count
      count = count + 1;
    }
  } else {
    digitalWrite(latchPin, LOW);
    // shift out seven segment display
    shiftOut(dataPin, clockPin, LSBFIRST, sevenSegmentDisplay[count%10]); //
    digitalWrite(latchPin, HIGH); 
  }
}
