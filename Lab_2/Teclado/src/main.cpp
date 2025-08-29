#include <Arduino.h>
#include <Keyboard.h>

// PINES DE LOS 4 PULSADORES
#define BT_W 2
#define BT_A 3
#define BT_S 4
#define BT_D 5


void setup() {
  // put your setup code here, to run once:
  
  pinMode(BT_W, INPUT_PULLUP);
  pinMode(BT_A, INPUT_PULLUP);
  pinMode(BT_S, INPUT_PULLUP);
  pinMode(BT_D, INPUT_PULLUP);

  Keyboard.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  if (!digitalRead(BT_W)) {
    Keyboard.write('w');
    delay(200);
  }

  if (!digitalRead(BT_A)) {
    Keyboard.write('a');
    delay(200);
  }

  if (!digitalRead(BT_S)) {
    Keyboard.write('s');
    delay(200);
  }

  if (!digitalRead(BT_D)) {
    Keyboard.write('d');
    delay(200);
  }
}
