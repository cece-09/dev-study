#include <iostream>

template <typename T>
void print(T arg) {
    std::cout << arg << std::endl;
}

template <typename T, typename ...Types>
void print(T arg, Types... args) {
    std::cout << arg << " ";
    print(args...);
}

template <typename ... Ints>
int sum_all(Ints... nums) {
    print(nums...);
    return (... + nums);
}

int main() {
    int ans = sum_all(1, 2, 3, 4, 5);
    std::cout << ans << std::endl;
}