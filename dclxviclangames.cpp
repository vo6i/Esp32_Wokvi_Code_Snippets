void setup() {
  // Ничего не нужно настраивать
}

void loop() {
  tone(8, 440); // Нота Ля
  delay(200);
  tone(8, 880); // Нота Ля на октаву выше
  delay(200);
  noTone(8);    // Тишина
  delay(1000);
}
void setup() {
  Serial.begin(9600); // Открываем монитор порта (как консоль в браузере)
  pinMode(12, OUTPUT);
  pinMode(11, INPUT);
}

void loop() {
  digitalWrite(12, LOW); delayMicroseconds(2);
  digitalWrite(12, HIGH); delayMicroseconds(10);
  digitalWrite(12, LOW);
  
  long duration = pulseIn(11, HIGH);
  int distance = duration * 0.034 / 2; // Формула перевода звука в см
  
  Serial.print("Расстояние: ");
  Serial.println(distance);
  
  if (distance < 20) {
    Serial.println("!!! СЛИШКОМ БЛИЗКО !!!");
  }
  delay(500);
}
void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  // Плавно зажигаем (как в шейдерах через синус)
  for (int i = 0; i <= 255; i++) {
    analogWrite(9, i); 
    delay(5);
  }
  // Плавно гасим
  for (int i = 255; i >= 0; i--) {
    analogWrite(9, i);
    delay(5);
  }
}
