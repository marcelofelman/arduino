// IN1 = AR13 - LEFT FORWARD
// IN2 = AR12 - LEFT BACKWARDS
// IN3 = AR8  - RIGHT BACKWARDS
// IN4 = AR9  - RIGHT FORWARD

#define trigPin 2
#define echoPin 3

void setup() {
  Serial.begin (9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
    float distance = getDistance();

    if(distance < 20) {
      moveBackwards();
      delay(1000);
      turnOff();
      delay(10000);
    }

    moveForward();
    delay(100);
}

float getDistance() {
   // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
  float duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  return (duration / 2) * 0.0343;
}

void leftEngineForward() {
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
}

void rightEngineForward() {
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
}

void leftEngineBackwards() {
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
}

void rightEngineBackwards() {
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
}

void leftEngineStop() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
}


void rightEngineStop() {
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
}

void moveForward() {
  leftEngineForward();
  rightEngineForward();
}

void moveBackwards() {
  leftEngineBackwards();
  rightEngineBackwards();
}

void turnLeft() {
  leftEngineStop();
  rightEngineForward();
}

void turnRight() {
  leftEngineForward();
  rightEngineStop();
}

void turnOff() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
}
