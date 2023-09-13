#include <IRremote.h>

// This value being the same as the value sent in the IR write function is a coincidence
const int powerButton = 12;


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
