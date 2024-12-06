namespace Stelo {
    template<typename T, typename CLASS, T(*FuncGet)(CLASS* obj),
        void (*FuncSet)(CLASS* obj, const T& value)>
    class SettingAccessor {
    public:
        T data; 
        CLASS* class_ptr;

        SettingAccessor(CLASS* obj, const T& intial) : 
            class_ptr(obj), data(intial) {}

        // getter oprate
        T& operator()() {
            return data;
        }
        T& operator->() {
            return data;
        }
        T& get() {
            return FuncGet ? FuncGet(class_ptr) : data;
        }

        // setter oprate
        void set(const T& new_value) {
            data = new_value;
            if (FuncSet) {
                FuncSet(class_ptr, new_value);
            }
        }
        T& operator=(const T& new_value) {
            data = new_value;
            if (FuncSet) {
                FuncSet(class_ptr, new_value);
            }
            return data;
        }

        T& operator+(const T& value) {
            return FuncGet ? FuncGet(class_ptr) : data + value;
        }

        T& operator-(const T& value) {
            return FuncGet ? FuncGet(class_ptr) : data - value;
        }

        T& operator*(const T& value) {
            return FuncGet ? FuncGet(class_ptr) : data * value;
        }

        T& operator/(const T& value) {
            return FuncGet ? FuncGet(class_ptr) : data / value;
        }
    };

#define Setting(T, name_variable, CLASS, func_get, func_set, initial_value) \
private: \
    static T get_##name_variable(CLASS* obj) func_get \
    static void set_##name_variable(CLASS* obj, const T& value) func_set \
public: \
    Stelo::SettingAccessor< \
        T, CLASS, &CLASS::get_##name_variable, &CLASS::set_##name_variable \
    > name_variable{ this, initial_value };
}
