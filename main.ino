int const outputA =6;
int const outputB=7;
float counter = 0;
int aState;
int aLastState;

void setup() {
  // put your setup code here, to run once:
pinMode(outputA, INPUT);
pinMode(outputB, INPUT);
Serial.begin(9600);
aLastState = digitalRead(outputA);
}

void loop() {
  // put your main code here, to run repeatedly:
aState= digitalRead(outputA);
if (aState != aLastState){
  if (digitalRead(outputB) != aState){
    counter +=1;
  }
  else{
    counter -=1;
  }
  Serial.print("Postion: ");
  Serial.println(counter);
}
aLastState = aState;
}
