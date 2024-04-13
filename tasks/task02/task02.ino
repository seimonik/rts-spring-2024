#include <TaskManagerIO.h>

const int pinsCount = 5;
int* ledStates = new int[pinsCount];
int pins[pinsCount] = {3, 5, 6, 9, 10};
unsigned long* intervalsArr = new unsigned long[pinsCount];

void setup() {
  for (int i = 0; i < pinsCount; ++i) {
    ledStates[i] = LOW;
    pinMode(pins[i], OUTPUT);
  }

  intervalsArr[0] = 10000;
  intervalsArr[1] = 1000;
  intervalsArr[2] = 500;
  intervalsArr[3] = 100;
  intervalsArr[4] = 50;

  taskid_t taskId0 = taskManager.scheduleFixedRate(intervalsArr[0], [] {
    if (ledStates[0] == LOW) {
      ledStates[0] = HIGH;
    }
    else {
      ledStates[0] = LOW;
    }

    digitalWrite(pins[0], ledStates[0]);
  }, TIME_MICROS);

  taskid_t taskId1 = taskManager.scheduleFixedRate(intervalsArr[1], [] {
    if (ledStates[1] == LOW) {
      ledStates[1] = HIGH;
    }
    else {
      ledStates[1] = LOW;
    }

    digitalWrite(pins[1], ledStates[1]);
  }, TIME_MICROS);

  taskid_t taskId2 = taskManager.scheduleFixedRate(intervalsArr[2], [] {
    if (ledStates[2] == LOW) {
      ledStates[2] = HIGH;
    }
    else {
      ledStates[2] = LOW;
    }

    digitalWrite(pins[2], ledStates[2]);
  }, TIME_MICROS);

  taskid_t taskId3 = taskManager.scheduleFixedRate(intervalsArr[3], [] {
    if (ledStates[3] == LOW) {
      ledStates[3] = HIGH;
    }
    else {
      ledStates[3] = LOW;
    }

    digitalWrite(pins[3], ledStates[3]);
  }, TIME_MICROS);

  taskid_t taskId4 = taskManager.scheduleFixedRate(intervalsArr[4], [] {
    if (ledStates[4] == LOW) {
      ledStates[4] = HIGH;
    }
    else {
      ledStates[4] = LOW;
    }

    digitalWrite(pins[4], ledStates[4]);
  }, TIME_MICROS);

  taskid_t taskId5 = taskManager.scheduleFixedRate(intervalsArr[5], [] {
    if (ledStates[5] == LOW) {
      ledStates[5] = HIGH;
    }
    else {
      ledStates[5] = LOW;
    }

    digitalWrite(pins[5], ledStates[5]);
  }, TIME_MICROS);
}

void loop() {
  taskManager.runLoop();
}
