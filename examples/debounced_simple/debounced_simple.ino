#include <dsg_button.h>

#define BTN_PIN 7
#define BTN_DEBOUNCE 25

DSG_Button btn(BTN_PIN, BTN_DEBOUNCE); // RAM: +8 bytes, pin 7, debounce time = 25 ms

void setup() {
    // Serial port
    Serial.begin(9600, SERIAL_8N1);  // RAM: +173 bytes

    // Button
    btn.begin();
}

void loop() {
    btn.read();
    if (btn.get()) {
        Serial.println(F("Button On"));
    } else {
        Serial.println(F("Button Off"));
    }
    delay(250);
}
