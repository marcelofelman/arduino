int red = 13;
int yellow = 8;
int blue = 11;
int duration = 50;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  turnAllOff();
}

void loop() {
  for(int j=0; j<10; j++) {  
    for(int i=0; i<10; i++) {
      digitalWrite(red, HIGH);
      delay(duration);
      digitalWrite(red, LOW);
      delay(duration);
    }
    
    digitalWrite(yellow, HIGH);
    delay(duration);
    digitalWrite(yellow, LOW);
  }
  digitalWrite(blue, HIGH);
  delay(duration*10);
  digitalWrite(blue, LOW);
  delay(duration);

  magicDance();
}

void turnAllOff() {
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(blue, LOW);
}

void turnAllOn() {
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
  digitalWrite(blue, HIGH);
}

void magicDance() {
  turnAllOff();
  for(int i=0; i<5; i++) {
    turnAllOn();
    delay(duration);
    turnAllOff();
    delay(duration);
  }

  for(int i=0; i<5; i++) {
    digitalWrite(red, HIGH);
    delay(duration*2);
    digitalWrite(yellow, HIGH);
    delay(duration*2);
    digitalWrite(blue, HIGH);
    delay(duration*2);
    turnAllOff();
    delay(duration);
  }

  for(int i=0; i<5; i++) {
    turnAllOn();
    delay(duration);
    turnAllOff();
    delay(duration);
  }

  delay(duration*10);
}
