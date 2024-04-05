#include <TaskManagerIO.h>

#define NUMBER_OF_PINS 5
const int Pins[NUMBER_OF_PINS] = {3, 5, 6, 9, 10};
const TimePeriod Period[NUMBER_OF_PINS] = {repeatMillis(10), repeatMillis(1), repeatMicros(500), repeatMicros(100), repeatMicros(50)};

taskid_t tasks[NUMBER_OF_PINS];

class MyClassToSchedule : public Executable {
  public:
    int state = LOW;
    int pin;

    void exec() override {
      // code to be executed upon schedule

      digitalWrite(pin, state);
      state = (state == LOW) ? HIGH : LOW;
    }
};

// Create an instance
MyClassToSchedule Schedule[NUMBER_OF_PINS];

void setup() {
  for (int i = 0; i < NUMBER_OF_PINS; ++i) {
    Schedule[i] = MyClassToSchedule();
    Schedule[i].pin = Pins[i];
    
    pinMode(Pins[i], OUTPUT);

    // Register with taskManager for once a second execution
    tasks[i] = taskManager.schedule(Period[i], &Schedule[i]);
  }
}

void loop() {
  taskManager.runLoop();
}
