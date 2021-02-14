# define dirPin 3
# define stepPin 2
# define stepsPerRevolution 800
long state = 0;

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(115200);
  Serial1.begin(9600);
}

  
void loop() {
  // Set the spinning direction clockwise:
  state = Serial.parseInt();
  
  if(state==1){  
    digitalWrite(dirPin, HIGH);
  }
  else if(state==-1){
    digitalWrite(dirPin, LOW);
  }

  if(state!=0){
  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
    }
  }
  delay(2000);
}
