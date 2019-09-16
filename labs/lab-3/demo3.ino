//these teensy pins are PWM capable pins
int greenLED = 3;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
int blueLED = 4;//2.3V, ~111ohm
int redLED = 5;//1.6V, ~189ohm

int pushButton = 12;
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
  counter = 0;
  while(counter < 1)
  { 
    Serial.println("in the while loop");
 
    randomSeed(analogRead(0));
 
    dutyCycleRandNumber = random(255);
    analogWrite(greenLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(255);
    analogWrite(redLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(255);
    analogWrite(blueLED, dutyCycleRandNumber);
    delay(500);
    
    if(digitalRead(pushButton) == HIGH)//first press of pushbutton
    {
      Serial.println("First button press");
      counter++;
     
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, LOW);
     // delay(1000);
    }
  }//end while loop

  while(counter > 0 && counter < 10)
  {
    //Serial.println("In the next while loop");
    if(digitalRead(pushButton)== HIGH)//out of the loop., now all subsequent press of pushbutton
    {
      Serial.println("another button press");
      freezeLight();
    }   
 }
}//end main

void freezeLight()
{
  dutyCycleRandNumber = random(255);
  analogWrite(greenLED, dutyCycleRandNumber);
  dutyCycleRandNumber = random(255);
  analogWrite(redLED, dutyCycleRandNumber);
  dutyCycleRandNumber = random(255);
  analogWrite(blueLED, dutyCycleRandNumber);
  delay(500);
}
