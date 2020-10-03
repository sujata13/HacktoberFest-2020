#include<Servo.h>
Servo microservo;   //creating an object called microservo

void setup(){
  microservo.attach(9);     //attach output pin to 9(PWM pin)
}

void setup(){
  microservo.write(90);     //turn the servo motor by 90 degree
  delay(1000);              //wait for 1 second
  microservo.write(0);      //turn the servo motor bck to 0 degree
  delay(1000);
}
