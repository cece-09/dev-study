#include <iostream>
#include <string>

using namespace std;

template <typename T>
T my_max(T x, T y) {
    return (x > y) ? x : y;
}

template <typename T>
class Box {
    public:
        Box(T value): value(value) {}
        T get_value() const { return value; }
    private:
        T value;
};

int main() {
    int a = my_max<int>(5, 6);
    double b = my_max<double>(4.33, 5.1);
    cout << a << " " << b << endl;

    Box<string> box("hello world");
    cout << box.get_value() << endl;
}

