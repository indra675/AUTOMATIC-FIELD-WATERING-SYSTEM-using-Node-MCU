#define SOIL_PIN A0

#define ENB D1   // PWM speed control
#define IN3 D2   // Direction control 1
#define IN4 D3   // Direction control 2

#define MOISTURE_THRESHOLD 550
#define MOTOR_SPEED 200   // 0-255

void setup() {
  Serial.begin(115200);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

void loop() {

  int soilValue = analogRead(SOIL_PIN);

  Serial.print("Soil Value: ");
  Serial.print(soilValue);

  if (soilValue > MOISTURE_THRESHOLD) {
    // Soil dry -> Motor ON
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, MOTOR_SPEED);

    Serial.println(" | SOIL DRY - MOTOR ON");
  }
  else {
    // Soil wet -> Motor OFF
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0);

    Serial.println(" | SOIL WET - MOTOR OFF");
  }

  delay(1000);
}
