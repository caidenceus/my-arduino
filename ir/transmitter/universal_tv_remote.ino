#include <LowPower.h>
#include <IRremote.h>

const int irSendPin = 2;

const int powerButton = 3;
const int volumeUpButton = 4;
const int volumeDownButton = 5;
const int channelUpButton = 6;
const int channelDownButton = 7;


void setup() {
    Serial.begin(300);

    pinMode(powerButton, INPUT);
    pinMode(volumeUpButton, INPUT);
    pinMode(volumeDownButton, INPUT);
    pinMode(channelUpButton, INPUT);
    pinMode(channelDownButton, INPUT);

    // Send IR data on pin irSendPin
    IrSender.begin(irSendPin, true, USE_DEFAULT_FEEDBACK_LED_PIN);
}

int timer;
int modeCounter = 0;

void wakeUp() {
    timer = 0;
}

void loop() {
    // attachInterrupt(0, wakeUp, HIGH);
    while (true) {
        // (protocol, address, command, times to send)
        if (digitalRead(powerButton) == HIGH) {
            timer = 0;
            delay(50);
            IrSender.write(RC5, 0, 12, 1);
        }
        if (digitalRead(volumeUpButton) == HIGH) {
            timer = 0;
            delay(50);
            IrSender.write(RC5, 0, 16, 1);
        }
        if (digitalRead(volumeDownButton) == HIGH) {
            timer = 0;
            delay(50);
            IrSender.write(RC5, 0, 17, 1);
        }
        if (digitalRead(channelUpButton) == HIGH) {
            timer = 0;
            delay(50);
            IrSender.write(RC5, 0, 32, 1);
        }
        if (digitalRead(channelDownButton) == HIGH) {
            timer = 0;
            delay(50);
            IrSender.write(RC5, 0, 33, 1);
        }
        delay(1);
        timer += 1;
    }

    // LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}