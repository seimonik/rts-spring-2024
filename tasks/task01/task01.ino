const int PinsCount = 5;

unsigned long* pinMicros = new unsigned long[PinsCount];
unsigned long* pinIntervals = new unsigned long[PinsCount];
int* pinStates = new int[PinsCount];

void setup() {
  pinIntervals[0] = 10000; // 10 миллисекунд
  pinIntervals[1] = 1000; // 1 миллисекунд
  pinIntervals[2] = 500; // 500 микросекунд
  pinIntervals[3] = 100; // 100 микросекунд
  pinIntervals[4] = 50; // 50 микросекунд

  for (int i = 0; i < PinsCount; i++) {
    pinMicros[i] = 0;
    pinStates[i] = LOW;
    pinMode(i + 1, OUTPUT);
  }
}

void loop() {
  unsigned long micros_val = micros();

  for (int i = 0; i < PinsCount; i++) {
    if (micros_val - pinMicros[i + 1] >= pinIntervals[i + 1]) {
      pinMicros[i + 1] = micros_val;
      
      if (pinStates[i + 1] == LOW) {
        pinStates[i + 1] = HIGH;
      }
      else {
        pinStates[i + 1] = LOW;
      }
      
      digitalWrite(i + 1, pinStates[i + 1]);
    }
  }
}
