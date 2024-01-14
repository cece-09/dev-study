#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Parent: public exception {
    public:
        virtual const char* what() const noexcept override {
            return "Parent!\n";
        }
};

class Child: public Parent {
    public:
        const char* what() const noexcept override {
            return "Child!\n";
        }
};

int func(int c) {
    if(c == 1) {
        throw Parent();
    } else if(c == 2) {
        throw Child();
    }
    return 0;
}

#include <algorithm>
#include <vector>

int main() {
    // main codes
}