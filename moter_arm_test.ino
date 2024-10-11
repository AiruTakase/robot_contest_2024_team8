#define CW_PIN 2     // Pin connected to CW pulse input (Clockwise)
#define CCW_PIN 3    // Pin connected to CCW pulse input (Counterclockwise)

void setup() {
  // Set motor control pins as outputs
  pinMode(CW_PIN, OUTPUT);
  pinMode(CCW_PIN, OUTPUT);

  // Start with the motor stopped
  stopMotor(1000);  // Pass a duration (in milliseconds) to stop the motor
}

void loop() {
  // Rotate clockwise for 1 second
  rotateCW(1000);

  // Stop the motor for 1 second
  stopMotor(1000);

  // Rotate counterclockwise for 1 second
  rotateCCW(1000);

  // Stop the motor for 1 second
  stopMotor(1000);
}

void rotateCW(int duration) {
  long startTime = millis();
  while (millis() - startTime < duration) {
    digitalWrite(CW_PIN, HIGH);  // Activate CW rotation
    delayMicroseconds(500);      // Adjust this value to control the motor speed
    digitalWrite(CW_PIN, LOW);
    delayMicroseconds(500);      // Adjust this value to control the motor speed
  }
}

void rotateCCW(int duration) {
  long startTime = millis();
  while (millis() - startTime < duration) {
    digitalWrite(CCW_PIN, HIGH); // Activate CCW rotation
    delayMicroseconds(500);      // Adjust this value to control the motor speed
    digitalWrite(CCW_PIN, LOW);
    delayMicroseconds(500);      // Adjust this value to control the motor speed
  }
}

void stopMotor(int duration) {
  digitalWrite(CW_PIN, LOW);   // Stop CW rotation
  digitalWrite(CCW_PIN, LOW);  // Stop CCW rotation
  delay(duration);             // Keep motor stopped for the specified time
}