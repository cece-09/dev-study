#include <iostream>
#include <utility>
#include <initializer_list>

using namespace std;

class matrix_type {
    private:
    public:
        int rows;
        int cols;
        matrix_type(int rows, int cols): rows(rows), cols(cols){};
        
};

class printer {
    private:
        const matrix_type& A;
    public:
        printer(const matrix_type& A): A(A){};
        void print() {
            cout << A.rows << " " << A.cols << endl;
        }
};

class node {
    public:
        node(int key): key(key) {};
        int get_key() const { return key; }
    private:
        int key;
};

class vec {
    public:
        explicit vec(int n): my_size(n), data(new double[my_size]){
            for(int i = 0; i < my_size; ++i) {
                data[i] = i * 2;
            }
        };
        double find(int i) const { return data[i]; }
        int size() const { return my_size; }
    private:
        int my_size;
        double* data;
};

double dot(const vec& a, const vec& b) {
    if(a.size() != b.size())
        throw invalid_argument("vectors must be of the same size");

    double sum = 0;
    for(int i = 0; i < a.size(); ++i) {
        sum += a.find(i) * b.find(i);
    }
    return sum;
}

class my_date {
    private:
        int year;
        int month;
        int day;
    
    public:
        my_date(int d): my_date{2024, 1, d} {};
        my_date(int m, int d): my_date(2024, m, d) {};
        my_date(int y, int m, int d)
            : year(y), month(m), day(d) {}
        
        void print() {
            cout << year << "-" << month << "-" << day << endl;
        }
};

class mclass {
    private:
        int data;
    public:
        mclass(int d): data(d){
            cout << "constructor" << endl;
        };
        mclass(mclass& m): data(m.data) {
            cout << "copy constructor" << endl;
        }
        mclass(mclass&& m): data(m.data) {
            m.data = 0;
            cout << "move constructor" << endl;
        }
        mclass& operator=(mclass& m) {
            data = m.data;
            cout << "copy assign oper" << endl;
            return *this;
        }
        mclass& operator=(mclass&& m) {
            if(this != &m) {
                data = m.data;
                m.data = 0;
            }
            cout << "move assign oper" << endl;
            return *this;
        }
        ~mclass() {
            cout << "destructor" << endl;
        }

        /* for access */
        int& get() { return data; }
};

inline int& real(mclass& m) { return m.get(); }

    // int&& r = a + b;
    // cout << r << endl;
    // r++;
    // cout << r << endl;

int main() {
    int a = 3;
    int b = 5;

    int&& mr = move(b);
    cout << "mr: " << mr << ", b: " << b << endl;
    mr++;
    cout << "mr: " << mr << ", b: " << b << endl;
}
