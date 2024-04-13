  #include <TaskManagerIO.h>

  const int pinsCount = 5;
  int ledStates[] = {LOW, LOW, LOW, LOW, LOW};
  int pins[pinsCount] = {3, 5, 6, 9, 10};

  void setup() {
    for (int i = 0; i < pinsCount; ++i) {
      pinMode(pins[i], OUTPUT);
    }

    taskid_t taskId0 = taskManager.scheduleFixedRate(10000, [] {
      if (ledStates[0] == LOW) {
        ledStates[0] = HIGH;
      }
      else {
        ledStates[0] = LOW;
      }

      digitalWrite(pins[0], ledStates[0]);
    }, TIME_MICROS);

    taskid_t taskId1 = taskManager.scheduleFixedRate(1000, [] {
      if (ledStates[1] == LOW) {
        ledStates[1] = HIGH;
      }
      else {
        ledStates[1] = LOW;
      }

      digitalWrite(pins[1], ledStates[1]);
    }, TIME_MICROS);

    taskid_t taskId2 = taskManager.scheduleFixedRate(500, [] {
      if (ledStates[2] == LOW) {
        ledStates[2] = HIGH;
      }
      else {
        ledStates[2] = LOW;
      }

      digitalWrite(pins[2], ledStates[2]);
    }, TIME_MICROS);

    taskid_t taskId3 = taskManager.scheduleFixedRate(100, [] {
      if (ledStates[3] == LOW) {
        ledStates[3] = HIGH;
      }
      else {
        ledStates[3] = LOW;
      }

      digitalWrite(pins[3], ledStates[3]);
    }, TIME_MICROS);

    taskid_t taskId4 = taskManager.scheduleFixedRate(50, [] {
      if (ledStates[4] == LOW) {
        ledStates[4] = HIGH;
      }
      else {
        ledStates[4] = LOW;
      }

      digitalWrite(pins[4], ledStates[4]);
    }, TIME_MICROS);
  }

  void loop() {
    taskManager.runLoop();
  }
