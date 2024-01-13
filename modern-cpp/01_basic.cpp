#include <iostream>

using namespace std;

class MyString {
    char *str_content;
    int str_len;
    int mem_capacity;

    public:
    MyString();
    MyString(const char* str);
    MyString(const MyString &str);
    void reserve(int size);
    MyString operator+(const MyString &s);
    ~MyString();

    int length() const;
    void print();
    void println();
};

int main() {
//   MyString str1("hello");
//   MyString str2("world");

//   cout << "--------" << endl;
//   MyString str3 = str1 + str2;
//   str3.println();
    int&& a = 5;
    cout << a << endl;
}

/***/
MyString::MyString() {
    cout << "constructor" << endl;
    str_len = 0;
    mem_capacity = 0;
    str_content = nullptr;
}

MyString::MyString(const char* str) {
    cout << "contructor" << endl;
    str_len = strlen(str);
    mem_capacity = str_len;
    str_content = new char[str_len];

    for(int i = 0; i < str_len; ++i) str_content[i] = str[i];
}

MyString::MyString(const MyString &str) {
    cout << "copy constructor" << endl;
    str_len = str.str_len;
    mem_capacity = str.str_len;
    str_content = new char[str_len];

    for(int i = 0; i < str_len; ++i)
        str_content[i] = str.str_content[i];
}

MyString::~MyString() { delete[] str_content; }

void MyString::reserve(int size) {
    if(size > mem_capacity) {
        char *prev_str_content = str_content;

        str_content = new char[size];
        mem_capacity = size;
        for(int i = 0; i < str_len; ++i)
            str_content[i] = prev_str_content[i];
        
        if(prev_str_content != nullptr)
            delete[] prev_str_content;
    }
}

MyString MyString::operator+(const MyString &s) {
    MyString str;
    str.reserve(str_len + s.str_len);
    for(int i = 0; i < str_len; ++i)
        str.str_content[i] = str_content[i];
    for(int i = 0; i < s.str_len; ++i)
        str.str_content[str_len + i] = s.str_content[i];
    str.str_len = str_len + s.str_len;
    return str;
}

int MyString::length() const { return str_len; }

void MyString::print() {
    for(int i = 0; i < str_len; ++i)
        cout << str_content[i];
}

void MyString::println() {
    for(int i = 0; i < str_len; ++i)
        cout << str_content[i];
    
    cout << endl;
}