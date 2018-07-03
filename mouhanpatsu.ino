#include <Servo.h>

Servo servo1, servo2;
int num1 = 0, num2 = 0;
String str = "";
int state = LOW, pre_state = LOW;
int mode = 0; // 0:上げる前 1:上げた後

void setup() {
  pinMode(10, INPUT_PULLUP);
  servo1.attach(7);
  servo2.attach(8);
  num1 = 30;
  num2 = 140;
  motor1(num1);
  motor2(num2);
  Serial.begin(9600);
}

void loop() {
  state = digitalRead(10);
  Serial.print(state);
  Serial.print(" : ");
  Serial.println(pre_state);

  if (state != pre_state) {
    num1 = 170;
    num2 = 30;
    motor1(num1);
    motor2(num2);
    delay(5000);

    num1 = 30;
    num2 = 140;
    motor1(num1);
    motor2(num2);
    delay(5000);

    state = digitalRead(10);
  }

  pre_state = state;
  delay(100);
}

void motor1(int num) {
  servo1.write(num);
}

void motor2(int num) {
  servo2.write(num);
  //Serial.print("num : ");
  //Serial.println(num);
}
