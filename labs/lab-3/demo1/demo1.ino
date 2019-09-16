//these teensy pins are PWM capable pins
int greenLED = 3;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
int blueLED = 4;//2.3V, ~111ohm
int redLED = 5;//1.6V, ~189ohm

//these pins are NOT PWM capable pins
//int greenLED = 7;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
//int blueLED = 8;//2.3V, ~111ohm
//int redLED = 12;//1.6V, ~189ohm

int pushButton = 14;
int myDelay = 800;
int counter;  

long dutyCycleRandNumber;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(pushButton, INPUT);
  pinMode(0, INPUT);//use this open circuited pin for a seed to the random number generator

  //attachInterrupt(pushButton, changeLights, CHANGE);//for task 6, demo #4   
}

void loop() {
   digitalWrite(greenLED, 1);
   delay(myDelay);
   digitalWrite(greenLED, 0);

   digitalWrite(redLED, 1);
   delay(myDelay);
   digitalWrite(redLED, 0);

   digitalWrite(blueLED, 1);
   delay(myDelay);
   digitalWrite(blueLED, 0);

  
}//end main
