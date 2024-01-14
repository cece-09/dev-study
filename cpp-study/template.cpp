#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
void change_lvr(T& val) { val = -1 * val; }

template <typename T>
void change_rvr(T&& val) { val = -1 * val; }

template <typename T>
void change_upt(unique_ptr<T>& val) { *val = -(*val); }

template <typename T>
class complex {
    T r, c;
    public:
        complex(T _r, T _c): r(_r), c(_c) {};
};

template <typename T>
using ptr = T*;

int main() {
    int a = 10;
    ptr<int> pt = &a;
    cout << pt << " " << *pt << endl;
}

