// Dog Fetch Machine — continuous spin test
// Wiring assumed:
//   Driver 1 RPWM -> D9
//   Driver 2 RPWM -> D10
//   Both drivers: R_EN + L_EN -> 5V rail
//   Both drivers: LPWM -> GND rail
//   Common ground between Uno and motor supply

int RPWM1 = 9;    // Driver 1 speed signal
int RPWM2 = 10;   // Driver 2 speed signal

int run = 80;    // 0-255. Speed. Raise toward 255 for faster.


void setup() {
  Serial.begin(9600);
  Serial.println("BOOT");

  pinMode(RPWM1, OUTPUT);
  pinMode(RPWM2, OUTPUT);

  // Gentle ramp so both motors start together and don't slam the supply
  for (int s = 0; s <= run; s += 5) {
    analogWrite(RPWM1, s);
    analogWrite(RPWM2, s);
    delay(300);
    
  }
}

void loop() {
  // Hold both at full run speed, continuously
  analogWrite(RPWM1, run);
  analogWrite(RPWM2, run);
  
