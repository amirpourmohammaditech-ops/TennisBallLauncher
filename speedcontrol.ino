int RPWM1 = 9;    // Driver 1
int RPWM2 = 10;   // Driver 2
int POT = A0;     // potentiometer signal (yellow)

void setup() {
  Serial.begin(9600);
  pinMode(RPWM1, OUTPUT);
  pinMode(RPWM2, OUTPUT);
}

void loop() {
  int knob = analogRead(POT);              // 0–1023 from the knob
  int speed = map(knob, 0, 1023, 0, 255);  // convert to motor speed

  analogWrite(RPWM1, speed);
  analogWrite(RPWM2, speed);

  Serial.println(speed);   // watch it change as you turn the knob
  delay(50);
}
