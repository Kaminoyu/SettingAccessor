# SettingAccessor Template & Macro Setting

`SettingAccessor` is a flexible C++ template designed to manage class properties efficiently. By using custom `getter` and `setter` functions, it provides fine-grained control over how data is accessed and modified. The `Setting` macro simplifies property declaration, reducing boilerplate code.

---

## Features
- Automatically creates `getter` and `setter` for properties.
- Supports operators like `+`, `-`, `*`, `/` for direct manipulation.
- Allows default value initialization for properties.
- Easy to integrate into existing classes.
  ## Structure

### SettingAccessor
The `SettingAccessor` template takes 4 parameters:
- `T`: The data type of the property.
- `CLASS`: The type of the class that owns the property.
- `FuncGet`: Pointer to the `getter` function.
- `FuncSet`: Pointer to the `setter` function.

#### Key Methods:
- `get()`: Retrieves the value using the `getter`.
- `set(const T& new_value)`: Updates the value using the `setter`.
- Operators `+`, `-`, `*`, `/`: Enable direct manipulation of the property.

### Macro Setting
The `Setting` macro simplifies the declaration of a property with minimal syntax.

# Usage example
``` c++
#include <iostream>
#include "SettingAccessor.h" // file header

enum class PropertyUI {
    BACKGROUND
};

class Window {
    Setting(float, transparency, Window, 
        { return obj->transparency_value; }, 
        { obj->Update(PropertyUI::BACKGROUND); },
        1.0f);

public:
    float transparency_value = 1.0f;

    void Update(PropertyUI property_ui) {
        if (property_ui == PropertyUI::BACKGROUND) {
            std::cout << "Transparency updated to: " << transparency() << "\n";
        }
    }
};

int main() {
    Window window;

    // get property
    std::cout << "Initial Transparency: " << window.transparency() << "\n";

    // set property
    window.transparency = 0.5f;

    // oprate +
    window.transparency = window.transparency + 0.3f;

    return 0;
}
```
