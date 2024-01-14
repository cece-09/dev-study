#include <iostream>

using namespace std;

template<typename T> void foo(const T a) {
    cout << "T: " << typeid(T).name() << endl;
    cout << "a: " << typeid(a).name() << endl;
}

int main() {
    cout << __cplusplus << endl;
    foo(3);
    foo(3.3);
}