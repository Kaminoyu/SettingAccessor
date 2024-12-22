# Stelo::SettingAccessor - Flexible Property Management in C++

`SettingAccessor` is a template-based utility designed to provide a clean and efficient interface for managing class properties with flexible getter and setter mechanisms. It enables intuitive property access while encapsulating logic for data retrieval and assignment.

## Features

- **Custom Getter and Setter Logic**: Define your own logic for accessing and modifying properties.
- **Supports Arithmetic Operations**: Perform arithmetic operations directly on properties.
- **Simple Integration**: Easy to add to your project.
- **Macros for Convenience**: Quickly define properties with macros.

## How to Use

### 1. Include the Header File

Place the `SettingAccessor.h` file in your project and include it in your source files:

```cpp
#include "SettingAccessor.h"
```
### 2. Define a Property
Use the provided macros to define properties within your class.

**Example: Defining a Property with Both Getter and Setter**
```cpp
class MyClass {
    Setting(int, my_value, MyClass,
        {
            return ref->my_value.data; // Getter logic
        },
        {
            ref->my_value.data = value; // Setter logic
        },
        0 // Initial value
    );
};
```

**Example: Using Default Getter Only**
```cpp
class MyClass {
    SettingGetterDefault(int, my_value, MyClass,
        {
            ref->my_value.data = value; // Setter logic
        },
        0 // Initial value
    );
};
```

**Example: Using Default Setter Only**
```cpp
class MyClass {
    SettingSetterDefault(int, my_value, MyClass,
        {
            return ref->my_value.data; // Getter logic
        },
        0 // Initial value
    );
};
```
### 3. Access Properties
Once a property is defined, you can use it with the following syntax:

Setting a Value
```cpp
MyClass obj;
obj.my_value = 10;  // Calls the setter
```

Getting a Value
```cpp
int value = obj.my_value;  // Calls the getter
```

Arithmetic Operations
```cpp
obj.my_value += 5;  // Increment value by 5
obj.my_value *= 2;  // Multiply value by 2
```
### Integration in Larger Projects
- To use `SettingAccessor` as a header-only library:
- Copy `SettingAccessor.h` to your project.
Include the file wherever needed:
```cpp
#include "SettingAccessor.h"
```
### Advanced Topics
Custom Getter and Setter Logic
You can customize how values are retrieved and assigned. For example:
``` cpp
Setting(std::string, name, MyClass,
    {
        return ref->name.data + " (accessed)";
    },
    {
        ref->name.data = value + " (modified)";
    },
    "Default"
);
```
### Debugging
You can add debugging or logging logic directly within the getter and setter.

### FAQ
- **Q: Can I use this with primitive types?**
  
  -> Yes, SettingAccessor works with any type, including primitives and user-defined classes.

- **Q: What happens if I don’t define a getter or setter?**
  
  -> You can use the SettingGetterDefault or SettingSetterDefault macros to define properties with default behaviors.

- **Q: Is this thread-safe?**
  
  -> No, thread safety must be implemented separately if required.

### License
This library is open-sourced under the GNU General Public License v3.0. See the LICENSE file for more details.
