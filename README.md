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
            return ref->data; // Getter logic
        },
        {
            ref->data = value; // Setter logic
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
            ref->data = value; // Setter logic
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
            return ref->data; // Getter logic
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
