#include <Arduino.h>

class Motor {
  public:
    Motor(int enable, int a, int b);
    void setSpeed(int speed);
    void setDirection(bool dir);
    void stop();
    bool direction;
  private:
    int _enable;
    int _a;
    int _b;
    
};


Motor::Motor(int enable, int a, int b) {
  _enable = enable;
  _a = a;
  _b = b;
  pinMode(_enable, OUTPUT);
  pinMode(_a, OUTPUT);
  pinMode(_b, OUTPUT);
}

void Motor::setDirection(bool dir) {
  direction = dir;
}

void Motor::setSpeed(int speed) {
  if (direction) {
    digitalWrite(_a, HIGH);
    digitalWrite(_b, LOW);
  } else {
    digitalWrite(_a, LOW);
    digitalWrite(_b, HIGH);
  }
  analogWrite(_enable, speed);
}

void Motor::stop() {
  digitalWrite(_a, LOW);
  digitalWrite(_b, LOW);
}
