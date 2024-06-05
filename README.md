# Debouncer

[中文版](README_CN.md)

The Debouncer class in this header file [debouncer.h](debouncer.h) provides a way to debounce input values in Arduino projects.

## How to Use

To use the `Debouncer` class, follow these steps:

1. Include the `Debouncer.h` header file in your Arduino sketch.
2. Create an instance of the `Debouncer` class with the desired data type (e.g., `cyfney::Debouncer<int> debouncer(0)`).
3. Call the`Debounce(value)` method with the input value that needs to be debounced.
4. The `Debounce(value)` method will return the debounced value after the specified debounce duration.

## Class Members

- `Debouncer(const T& value, const uint64_t debounce_duration_ms = kDefaultDebounceDurationMs)`: Constructor to initialize the Debouncer class with an initial value and debounce duration.
- `Debounce(const T& value)`: Method to debounce the input value and return the debounced value.
- `operator()`: Overloaded operator to easily debounce input values using the ().
- `operator=`: Overloaded operator to assign debounced value directly.
- `operator()()` const: Overloaded operator to retrieve the last debounced value.

## Constants

- `kDefaultDebounceDurationMs`: Default debounce duration in milliseconds.

## Sample Usage

```c++
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

```

## Notes

- Adjust the debounce duration by passing a different value to the constructor or using the default value.
- Ensure that the input values are of the same data type as specified in the `Debouncer` class template.
- Refer to the comments in the header file for more information on each class member.

---

Feel free to customize and integrate the Debouncer class into your Arduino projects to debounce input values effectively.
