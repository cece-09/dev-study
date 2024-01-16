// 수치 연산
#include <iostream>
#include <limits>
#include <type_traits>

using namespace std;
template<typename T>
inline void test(const T& x) {
	cout << "x = " << x << " (";
	int oldp = cout.precision(numeric_limits<T>::digits10 + 1);
	cout << x << ")" << endl;
	cout.precision(oldp);
}

class pod {
    int x, y;
    public:
        pod() = default;
};

class abstract {
    int x, y;
    public:
        abstract(int x, int y): x(x), y(y){}
        virtual int addition() = 0;
};

#include <vector>
#include <utility>

int main() {
    vector<reference_wrapper<int>> v;
    cout << "referenct wrapper" << endl;
    // vector<int&> w;
}