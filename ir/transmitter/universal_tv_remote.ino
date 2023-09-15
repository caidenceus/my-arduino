#include <IRremote.h>

const int irSendPin = 2;

const int powerButton = 3;
const int volumeUpButton = 4;
const int volumeDownButton = 5;
const int channelUpButton = 6;
const int channelDownButton = 7;

const int appliancePowerButton = 12;


void setup() {
    Serial.begin(300);

    pinMode(powerButton, INPUT);
    pinMode(volumeUpButton, INPUT);
    pinMode(volumeDownButton, INPUT);
    pinMode(channelUpButton, INPUT);
    pinMode(channelDownButton, INPUT);

    pinMode(appliancePowerButton, INPUT);

    // Send IR data on pin irSendPin
    IrSender.begin(irSendPin, true, USE_DEFAULT_FEEDBACK_LED_PIN);
}


void loop() {
    while (1) {
        delay(500);

        // (protocol, address, command, times to send)
        if (digitalRead(powerButton) == HIGH) {
            int data = IrSender.write(RC5, 0, 12, 1);
            Serial.println(data);
        }
        if (digitalRead(volumeUpButton) == HIGH) {
            IrSender.write(RC5, 0, 16, 1);
        }
        if (digitalRead(volumeDownButton) == HIGH) {
            IrSender.write(RC5, 0, 17, 1);
        }
        if (digitalRead(channelUpButton) == HIGH) {
            IrSender.write(RC5, 0, 32, 1);
        }
        if (digitalRead(channelDownButton) == HIGH) {
            IrSender.write(RC5, 0, 33, 1);
        }
        if (digitalRead(appliancePowerButton) == HIGH) {
          IrSender.sendSAMSUNG(0xE0E040BF, 32);
          // IrSender.write(SAMSUNG, 45863, 4168);
        }
    }
}