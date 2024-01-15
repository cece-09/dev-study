// unique_ptr 구현해보자

#include <iostream>

template<typename T>
class unique_ptr {
    T* pt;
    
    public:
        // 생성자
        unique_ptr(T* p = nullptr): pt(p) { };
        // 복사 생성자 삭제
        unique_ptr(const T&) = delete;
        unique_ptr& operator=(const unique_ptr&) = delete;
        // 이동 생성자
        unique_ptr(unique_ptr&& up): pt(up.pt) {
            up.pt = nullptr;
            std::cout << "move constructor" << std::endl;
        }
        // 이동 대입 연산자
        unique_ptr& operator=(unique_ptr&& up) {
            if(this != &up) {
                delete pt;
                pt = up.pt;
                up.pt = nullptr;
            }
            std::cout << "move assignment operator" << std::endl;
            return *this;
        }
        // 소멸자
        ~unique_ptr() noexcept {
            delete pt;
            std::cout << "destructor" << std::endl;
        }

        // 접근자
        T* get()        const { return pt;  } 
        T* operator->() const { return pt;  }
        T& operator*()  const { return *pt; }
};

class mclass {
    public:
        int data;
        mclass(int data): data(data) {};
};

int main() {
    unique_ptr<mclass> up(new mclass(10));
    up->data = 45;

    using namespace std;
    cout << up->data << " " << up.get() << endl;
}