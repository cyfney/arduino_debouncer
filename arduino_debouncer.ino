#include <Arduino.h>

#include "debouncer.h"

namespace {
constexpr uint8_t kButtonPin = 2;
cyfney::Debouncer<uint8_t> g_debouncer(HIGH);
}  // namespace

void setup() {
  Serial.begin(115200);
  pinMode(kButtonPin, INPUT_PULLUP);
  Serial.println(String(F("Please change the pin ")) + kButtonPin + F(" level"));
}

void loop() {
  uint8_t debounced_value = g_debouncer.Debounce(digitalRead(kButtonPin));
  static uint8_t s_last_value = debounced_value;
  if (s_last_value != debounced_value) {
    Serial.println(String(F("Pin ")) + kButtonPin + F(" level changed to ") + debounced_value);
  }

  s_last_value = debounced_value;
}