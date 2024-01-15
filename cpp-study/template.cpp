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

template <typename T, unsigned N>
T sum(const T (&array)[N]) {
	T sum(0);
	for(int i = 0; i < N; ++i)
		sum += array[i];
	return sum;
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    cout << sum(arr) << endl;
}

