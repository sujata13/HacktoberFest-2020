int led = 13; //declare the variable
void setup() {
  pinMode(led,OUTPUT); //make the led variable as output
}

void loop() {
  digitalWrite(led,HIGH); // make 13th pin HIGH
  delay(1000);            // 1 second delay
  digitalWrite(led,LOW);  //make 13th pin LOW
  delay(1000);            //1 second delay
}