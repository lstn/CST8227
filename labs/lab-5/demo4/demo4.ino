int dataPin = 14;
int latchPin = 15;
int clockPin = 16;
 
const char common = 'a';    // common anode
//const char common = 'c';    // common cathode

bool decPt = true;  // decimal point display flag
IntervalTimer myTimer;
byte sevenSegmentDisplay[10] = {B00000011, //0
                                B10011111, //1
                                B00100101, //2
                                B00001101, //3
                                B10011001, //4
                                B01001001, //5
                                B11000001, //6
                                B00011111, //7
                                B00000001, //8
                                B00011001}; //9

void setup() 
{
  // initialize I/O pins
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT); 

  digitalWrite(dataPin, 0);
  digitalWrite(latchPin, 0);
  digitalWrite(clockPin, 0);
  myTimer.begin(resetNum, 1000000);
  
}
 
void loop() 
{

  // generate characters to display for hexidecimal numbers 0 to F
  for (int tens = 0; tens < 10; tens++) {
    for (int ones = 0; ones < 10; ones++) {
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, sevenSegmentDisplay[ones]);
      shiftOut(dataPin, clockPin, LSBFIRST, sevenSegmentDisplay[tens]);
      digitalWrite(latchPin, HIGH);
      
      delay(150);
    }
    delay(200);
  }
}

void resetNum() { //Interrupt ISR function; Called when interrupt occurs
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B00011111);
  shiftOut(dataPin, clockPin, LSBFIRST, B00011111);
  digitalWrite(latchPin, HIGH);
  delay(2000);
}
