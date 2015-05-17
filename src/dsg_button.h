#ifndef _DSG_BUTTON_H_
#define _DSG_BUTTON_H_

#include <stdint.h>

/**
 * De-bounced button (uses the pull-up resistor)
 *
 * Storage: 8 bytes SRAM.
 *
 * Returns (.get()) true when pressed and false when not.
 *
 * See also: http://www.arduino.cc/en/tutorial/debounce
 */
class DSG_Button {
public:
    // The default debounce time is 25 ms. One should not be able to press
    // and release a button for 0.05 (1/20) seconds, right?
    DSG_Button(uint8_t pin, uint16_t debounce_delay = 25);

    ~DSG_Button(void);

    void begin(void);

    void end(void);

    void read(void);

    inline bool get(void) const __attribute__ ((pure)) {
        return m_v;
    }

protected:
    // Setup
    uint8_t m_pin;               // 1 byte for the pin
    bool m_v;                    // 1 byte pressed or not
    // Debounce data
    uint16_t m_debounce_delay;   // 2 bytes delay between reads, could be one byte...
    unsigned long m_last_change; // 4 bytes last time the value changed (see millis())
};

#endif /* _DSG_BUTTON_H_ */
