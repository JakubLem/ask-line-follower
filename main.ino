const int motorA1 = 9;
const int motorA2 = 10;
const int motorB1 = 11;
const int motorB2 = 12;

const int lineFollowerLeft = 2;
const int lineFollowerRight = 3;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  pinMode(lineFollowerLeft, INPUT);
  pinMode(lineFollowerRight, INPUT);

  Serial.begin(9600);
}

void loop() {
  int leftSensor = digitalRead(lineFollowerLeft);
  int rightSensor = digitalRead(lineFollowerRight);

  if (leftSensor && rightSensor) {
    forward();
  } else if (leftSensor && !rightSensor) {
    right();
  } else if (!leftSensor && rightSensor) {
    left();
  } else {
    func_stop();
  }
}

void forward() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void right() {
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}

void left() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
}

void func_stop() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
}
