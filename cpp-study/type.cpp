#include <iostream>
#include <stdexcept>

template <typename T, unsigned N>
class vector {
    const static unsigned size = N;
    private:
        T data[N];
    
    public:
        // constructor 
        vector() = default;
        // copy constructor
        vector(const vector& v) {
            std::copy(v.data, v.data + N, data);
        } 
        // assign operator
        vector& operator=(const vector& v) {
            std::copy(v.data, v.data + N, data);
            return *this;
        }
        // destructor
        ~vector() = default; 

        // access operator
        T& operator[](unsigned i) {
            if (i < 0 || i > N-1) {
                throw std::out_of_range("index out of range");
            }
            return data[i];
        }
        // add operator
        vector operator+(const vector& v) const {
            vector sum;
            for(int i = 0; i < size; ++i)
                sum[i] = data[i] + v[i];
            return sum;
        }
        // show vector
        void show() {
            for(int i = 0; i < size; ++i)
                std::cout << data[i] << " ";
            std::cout << std::endl;
        }
};

int main() {
    vector<int, 5U> v;
    vector<int, 6U> w;
    v[0] = 1001;

    v.show();
    w.show();

    w = v; // 
    
    v.show();
    w.show();
}