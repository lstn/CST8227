int serPin = 14;
int latchPin = 15;
int clockPin = 16;
 
int leds = 0;
byte data = 0; 
int seq [20]={1,2,4,8,16,32,64,128,64,32,16,8,4,2,128,64,16,4,2,1};
int bitArray[] = {1, 3, 7, 15, 31, 63, 127, 255};

void setup() 
{
  pinMode(serPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);  
  
}
 
void loop() 
{
  for (int i=0;i<9; i++){

    shiftOut(serPin, clockPin, MSBFIRST ,0);//Shift most sig.bit first
    shiftOut(serPin, clockPin, MSBFIRST ,bitArray[i]);//Shift most sig.bit first
    digitalWrite(latchPin,HIGH);//Latch high-stop sending
    digitalWrite(latchPin,LOW);//Latch high-stop sending
    delay(150);
  }
    for (int i=0;i<8; i++){
    shiftOut(serPin, clockPin, MSBFIRST ,bitArray[i]);//Shift most sig.bit first
    shiftOut(serPin, clockPin, MSBFIRST ,255);//Shift most sig.bit first
    digitalWrite(latchPin,HIGH);//Latch high-stop sending
    digitalWrite(latchPin,LOW);//Latch high-stop sending
    delay(150);
  }
    for (int i=7;i>-1; i--){
    shiftOut(serPin, clockPin, MSBFIRST ,bitArray[i]);//Shift most sig.bit first
    shiftOut(serPin, clockPin, MSBFIRST ,255);//Shift most sig.bit first
    digitalWrite(latchPin,HIGH);//Latch high-stop sending
    digitalWrite(latchPin,LOW);//Latch high-stop sending
    delay(150);
  }

}
