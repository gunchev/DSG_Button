#include <Arduino.h>
#include "dsg_button.h"

DSG_Button::DSG_Button(uint8_t pin, uint16_t debounce_delay) :
        m_pin(pin), m_v(false), m_debounce_delay(debounce_delay), m_last_change(0) {
}

DSG_Button::~DSG_Button(void) {
    end();
}

void DSG_Button::begin(void) {
    // Uses extra space with no real benefit:
    // m_last_change = millis() - m_debounce_delay; // No problem if negative.
    m_last_change = millis(); // Good enough
    // Activate the pull-up resistor on the push-button pin.
    pinMode(m_pin, INPUT_PULLUP);
}

void DSG_Button::end(void) {
    // Restore the default PIN state.
    pinMode(m_pin, INPUT);
}

void DSG_Button::read(void) {
    // Read only after enough time has passed
    if ((millis() - m_last_change) < m_debounce_delay) // Signed negative is greater when used as unsigned ;-)
        return; // The button can still be bouncing up and down

    bool pressed = digitalRead(m_pin) == LOW; // When pressed digitalRead returns low (pin grounded)
    if (m_v != pressed) { // Change in state - record the current time and change the value.
        m_last_change = millis();
        m_v = pressed;
    }
}
