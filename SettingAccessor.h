``` cpp
#pragma once
#ifndef SETTING_ACCESSOR_H
#define SETTING_ACCESSOR_H

namespace Stelo {
    template<typename T, typename CLASS, T& (*FuncGet)(CLASS* ref),
        void (*FuncSet)(CLASS* ref, const T& value)>
    class SettingAccessor {
    public:
        CLASS* class_ptr;
        T data;

        SettingAccessor(CLASS* ref, const T& intial) :
            class_ptr(ref), data(intial) {
        }

        // getter operate
        T operator()() {
            return FuncGet ? *FuncGet(class_ptr) : data;
        }
        T& operator->() {
            return FuncGet ? FuncGet(class_ptr) : data;
        }
        T get() {
            return FuncGet ? *FuncGet(class_ptr) : data;
        }

        // setter operate
        void set(const T& value) {
            if (FuncSet) {
                FuncSet(class_ptr, value);
            }
            else {
                data = value;
            }
        }
        T operator=(const T& value) {
            if (FuncSet) {
                FuncSet(class_ptr, value);
            }
            else {
                data = value;
            }
            return data;
        }

        // arithmetic operators
        T operator+(const T& value) const {
            return FuncGet ? FuncGet(class_ptr) + value : data + value;
        }

        T operator-(const T& value) const {
            return FuncGet ? FuncGet(class_ptr) - value : data - value;
        }

        T operator*(const T& value) const {
            return FuncGet ? FuncGet(class_ptr) * value : data * value;
        }

        T operator/(const T& value) const {
            return FuncGet ? FuncGet(class_ptr) / value : data / value;
        }

        // compound assignment operators
        SettingAccessor& operator+=(const T& value) {
            if (FuncSet) {
                FuncSet(class_ptr, data + value);
            }
            else data += value;
            return *this;
        }

        SettingAccessor& operator-=(const T& value) {
            if (FuncSet) {
                FuncSet(class_ptr, data - value) ;
            }
            else data -= value;

            return *this;
        }

        SettingAccessor& operator*=(const T& value) {
            if (FuncSet) {
                FuncSet(class_ptr, data * value);
            }
            else data *= value;

            return *this;
        }

        SettingAccessor& operator/=(const T& value) {
            if (FuncSet) {
                FuncSet(class_ptr, data / value);
            }
            else data /= value;

            return *this;
        }
    };

#define Setting(T, name_variable, CLASS, getter, setter, initial_value) \
private: \
    static T& get_##name_variable(CLASS* ref) getter \
    static void set_##name_variable(CLASS* ref, const T& value) setter\
public: \
    Stelo::SettingAccessor< \
        T, CLASS, &CLASS::get_##name_variable, &CLASS::set_##name_variable\
    > name_variable{ this, initial_value }

#define SettingGetterDefault(T, name_variable, CLASS, setter, initial_value) \
private: \
    static void set_##name_variable(CLASS* ref, const T& value) setter \
public: \
    Stelo::SettingAccessor<T, CLASS, nullptr, &CLASS::set_##name_variable\
    > name_variable{ this, initial_value }

#define SettingSetterDefault(T, name_variable, CLASS, getter, initial_value) \
private: \
    static T& get_##name_variable(CLASS* ref) getter \
public: \
    Stelo::SettingAccessor< \
        T, CLASS, &CLASS::get_##name_variable, nullptr_t\
    > name_variable{ this, initial_value }
}
#endif // SETTING_ACCESSOR_HPP
```
