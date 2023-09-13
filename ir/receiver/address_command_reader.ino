#include <IRremote.h> // include the IRremote library

#define IR_RECEIVE_PIN 11 // define the IR receiver pin


void setup() {
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
    Serial.begin(9600); // begin serial communication with a baud rate of 9600
    IrReceiver.enableIRIn(); // enable the receiver
    IrReceiver.blink13(true); // enable blinking of the built-in LED when an IR signal is received
}


void loop() {
    // https://github.com/Arduino-IRremote/Arduino-IRremote/blob/master/src/IRProtocol.h#L107
    if (IrReceiver.decode()) {
        Serial.println("Protocol number");
        Serial.println(IrReceiver.decodedIRData.protocol);
        Serial.println("Address");
        Serial.println(IrReceiver.decodedIRData.address);
        Serial.println("IR command");
        Serial.println(IrReceiver.decodedIRData.command);
        Serial.println("Extra");
        Serial.println(IrReceiver.decodedIRData.extra);
        Serial.println("Raw data");
        Serial.println(IrReceiver.decodedIRData.decodedRawData);
        IrReceiver.resume(); // Enable receiving of the next value
    }
}