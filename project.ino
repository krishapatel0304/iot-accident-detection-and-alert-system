// Accident detection using Ultrasonic Sensor and Buzzer
#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 7

long duration;
int distance;
int thresholdDistance = 5;  // Distance in cm considered as accident or close obstacle

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send an ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  

  // Measure echo time
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;  // Convert to cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Accident detection condition
  if (distance > 0 && distance <= thresholdDistance) {
    Serial.println("⚠ Accident Detected! Object very close!");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500); // Buzzer ON duration
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(300);
}