const int sensorPin = A0;
const int fanPin = 9;
const float threshold = 30.0;

void setup() {
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(sensorPin);
  float voltage = reading * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100.0;

  Serial.print("Temperature: ");
  Serial.println(temperatureC);

  digitalWrite(fanPin,
    temperatureC >= threshold ? HIGH : LOW);

  delay(500);
}
