#include <Stepper.h>

//Analog Stick X pin
const int X_pin = 0;

//Step per rev
const int SPR = 1000;
//Initialize obj and pins for the stepper
Stepper myStepper(SPR, 8,9,10,11);

void setup() {
  myStepper.setSpeed(300);
  Serial.begin(9600);
}

void loop() {
 //Reading analog input of X axis
 Serial.print("X: ");
 
 //Set val for X axis
 int xVal = analogRead(X_pin);

  //If stick to the left, goes backwards
  if(xVal == 0){
    Serial.print("I am in 0");
    myStepper.step(1);
  }else{
  //If not moving, the motor stops
   myStepper.step(0);
  }

  //If stick to the right, goes foward
  if(xVal == 1023){
   Serial.print("I am in 1023");
   myStepper.step(-1);
  }else{
    //If not moving, the motor stops
    myStepper.step(0);
  }
    
  Serial.print("\n");

}
