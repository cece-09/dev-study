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

int main() {
    int c = 2; // child 예외를 throw해야 함

    try {
        func(c);
    } catch(Parent& p) {
        cout << "Parent catch!" << endl;
        cout << p.what();
    } catch(Child& c) {
        cout << "Child catch!" << endl;
        cout << c.what();
    }
}