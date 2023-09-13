#include <IRremote.h>

const int powerButton = 2;


void setup() {
    Serial.begin(300);
    pinMode(powerButton, INPUT);
    IrSender.begin(3, true, USE_DEFAULT_FEEDBACK_LED_PIN);
}


void loop() {
  int dataSent = 0;

  while (1) {
    delay(500);

    if (digitalRead(powerButton) == HIGH) {
      dataSent = IrSender.write(RC5, 0, 12, 1);
      Serial.print(dataSent);
    }
  }
}