#include <IRremote.h>

// This value being the same as the value sent in the IR write function is a coincidence
const int powerButton = 12;


void setup() {
    Serial.begin(300);

    // set pin 12 to listen for input from the button
    pinMode(powerButton, INPUT);

    // Send IR data on pin 3
    IrSender.begin(3, true, USE_DEFAULT_FEEDBACK_LED_PIN);
}


void loop() {
    int dataSent = 0;

    while (1) {
        // half a second
        delay(500);

        if (digitalRead(powerButton) == HIGH) {
            // 1 if data was sent, 0 otherwise
            dataSent = IrSender.write(RC5, 0, 12, 1);
            Serial.print(dataSent);
        }
    }
}
