//pins to use for resistive touchscreen
int posX = A0;
int negX = A2;
int posY = A1;
int negY = A3;

int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(19200);
}

void loop() {
  if(touchDetect()){
    //Serial.print("x:");
    Serial.print(readXPos());
    Serial.print(" ");
    //Serial.print(",y:");
    Serial.println(readYPos());
  } else {
    Serial.println("up");
  }
  delay(5);
}

boolean touchDetect(){
  pinMode(posX, INPUT_PULLUP);
  pinMode(negY, OUTPUT);
  pinMode(negX, INPUT);
  pinMode(posY, INPUT);
  digitalWrite(negY, LOW);
  if (digitalRead(posX) == LOW){
    delay(5);
    if (digitalRead(posX) == LOW){
      return true;
    }
  }
  return false;
}

int readXPos(){
  pinMode(posX, OUTPUT);
  pinMode(negY, INPUT);
  pinMode(negX, OUTPUT);
  pinMode(posY, INPUT);
  digitalWrite(posX, HIGH);
  digitalWrite(negX, LOW);
  //int v1 = (int)(analogRead(posY)*(1280.0/1023.0));
  return analogRead(posY);
}

int readYPos(){
  pinMode(posY, OUTPUT);
  pinMode(negX, INPUT);
  pinMode(negY, OUTPUT);
  pinMode(posX, INPUT);
  digitalWrite(posY, HIGH);
  digitalWrite(negY, LOW);
  //int v1 = (int)(analogRead(posX)*(800.0/1023.0));
  return analogRead(posX);
}
