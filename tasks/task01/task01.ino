int pinsCount = 5;
const int pins[] = {3, 5, 6, 9, 10};

int ledStates[] = {HIGH, HIGH, HIGH, HIGH, HIGH};

unsigned long microsArr[] = {0, 0, 0, 0, 0};

void setup() {
  for (int thisPin = 0; thisPin < pinsCount; thisPin++) {
    pinMode(pins[thisPin], OUTPUT);
  }
}

void loop() {
  unsigned long currentMicros = micros();

  // -------------- 1 ---------------
  if (currentMicros - microsArr[0] >= 10000) {
    microsArr[0] = currentMicros;

    if (ledStates[0] == LOW) {
      ledStates[0] = HIGH;
    } else {
      ledStates[0] = LOW;
    }

    digitalWrite(pins[0], ledStates[0]);
  }

  // -------------- 2 ---------------
  if (currentMicros - microsArr[1] >= 1000) {
    microsArr[1] = currentMicros;

    if (ledStates[1] == LOW) {
      ledStates[1] = HIGH;
    } else {
      ledStates[1] = LOW;
    }

    digitalWrite(pins[1], ledStates[1]);
  }

  // -------------- 3 ---------------
  if (currentMicros - microsArr[2] >= 500) {
    microsArr[2] = currentMicros;

    if (ledStates[2] == LOW) {
      ledStates[2] = HIGH;
    } else {
      ledStates[2] = LOW;
    }

    digitalWrite(pins[2], ledStates[2]);
  }

  // -------------- 4 ---------------
  if (currentMicros - microsArr[3] >= 100) {
    microsArr[3] = currentMicros;

    if (ledStates[3] == LOW) {
      ledStates[3] = HIGH;
    } else {
      ledStates[3] = LOW;
    }

    digitalWrite(pins[3], ledStates[3]);
  }

  // -------------- 5 ---------------
  if (currentMicros - microsArr[4] >= 50) {
    microsArr[4] = currentMicros;

    if (ledStates[4] == LOW) {
      ledStates[4] = HIGH;
    } else {
      ledStates[4] = LOW;
    }

    digitalWrite(pins[4], ledStates[4]);
  }
}
