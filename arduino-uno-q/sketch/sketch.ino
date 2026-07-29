#include <Wire.h>

#define SLAVE_ADDRESS 0x08
#define LED_PIN 5

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveEvent);
}

void loop() {
  // no hace falta nada acá, todo pasa en receiveEvent
}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    char c = Wire.read();
    if (c == '1') {
      digitalWrite(LED_PIN, HIGH);
    } else if (c == '0') {
      digitalWrite(LED_PIN, LOW);
    }
  }
}
