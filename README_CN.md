# Debouncer

这个头文件[debouncer.h](debouncer.h)中的 `Debouncer` 类提供了一种在 Arduino 项目中去抖动输入值的方法。

## 如何使用

要使用 `Debouncer` 类，按照以下步骤进行操作：

1. 在你的 Arduino 项目中包含 `Debouncer.h` 头文件。
2. 使用所需的数据类型创建 `Debouncer` 类的实例（例如 `cyfney::Debouncer<int> debouncer(0)`）。
3. 使用输入值调用 `Debounce(value)` 方法以进行去抖动。
4. `Debounce(value)` 方法将在指定的去抖时间后返回去抖值。

## 类成员

- `Debouncer(const T& value, const uint64_t debounce_duration_ms = kDefaultDebounceDurationMs)`: 用于使用初始值和去抖时间初始化 `Debouncer` 类的构造函数。
- `Debounce(const T& value)`: 用于去抖输入值并返回去抖值的方法。
- `operator()`: 重载运算符，用于使用 `()` 轻松去抖动输入值。
- `operator=`: 重载运算符，用于直接分配去抖后的值。
- `operator()() const`: 重载运算符，用于检索最后去抖值。

## 常量

- `kDefaultDebounceDurationMs`: 默认的去抖时间（毫秒）。

## 示例用法

```cpp
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

## 注意事项

- 通过向构造函数传递不同的值或使用默认值来调整去抖时间。
- 确保输入值与 `Debouncer` 类模板中指定的数据类型相同。
- 有关每个类成员的更多信息，请参考头文件中的注释。

---

随意定制并将 Debouncer 类集成到您的 Arduino 项目中，以有效去抖动输入值。
