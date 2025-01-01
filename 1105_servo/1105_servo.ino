#include <Servo.h>
Servo m;
void setup() {
  m.attach(9);
}

void loop() {
  m.write(0);
  delay(200);
  m.write(90);
  delay(200);
  m.write(180);
  delay(200);

}
