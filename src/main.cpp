#include <Arduino.h>

#define LED_PIN 9
#define BUTTON_PIN 2

// Brightness increment step (0~255)
const uint8_t STEP = 64;  // 4 levels: 0, 64, 128, 192
const unsigned long DEBOUNCE_MS = 25;

uint8_t brightness = 0;          // Current brightness 0~255
bool lastBtn = HIGH;             // INPUT_PULLUP: not pressed = HIGH
unsigned long lastChange = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  analogWrite(LED_PIN, brightness); // Initial brightness
}

void loop() {
  bool reading = digitalRead(BUTTON_PIN);
  unsigned long now = millis();

  // Simple debounce: wait a short time after state change before confirming
  if (reading != lastBtn && (now - lastChange) > DEBOUNCE_MS) {
    lastChange = now;
    // Detect "button press moment" (HIGH -> LOW falling edge)
    if (reading == LOW && lastBtn == HIGH) {
      // Each press increases brightness, wraps back to 0 after 192
      brightness = (brightness + STEP) % 256;
      analogWrite(LED_PIN, brightness);
    }
    lastBtn = reading;
  }
}
