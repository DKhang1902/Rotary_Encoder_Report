#include <Servo.h>
Servo myservo;
int pos = 0;

int const outputA =6;
int const outputB=7;
float counter = 0;
int aState;
int aLastState;

int buttonRead = 10;
void setup() {
  // put your setup code here, to run once:
pinMode(outputA, INPUT);
pinMode(outputB, INPUT);
pinMode(buttonRead, INPUT);
digitalWrite(buttonRead, HIGH);
Serial.begin(9600);
aLastState = digitalRead(outputA);

 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(counter);
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
aState= digitalRead(outputA);
if (aState != aLastState){
  if (digitalRead(outputB) != aState && aState == 1){
    counter += 5;
    Serial.print("Postion: ");
  Serial.println(counter);
  }
  else{
    if (aState == 1){
    counter -=5;
    Serial.print("Postion: ");
  Serial.println(counter);
    }
  }
}
myservo.write(counter);
aLastState = aState;
if (digitalRead(buttonRead) == 0){
  counter = 0;
}
if (counter > 180){
  counter = 180;
}
else if (counter < 0){
  counter = 0;
}
}
