#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

template<typename T>
class idx_finder {
	bool reversed;

	public:
        // constructor
		idx_finder(bool r): reversed(r) {};
        // operator
		int operator()(const T& key, const std::vector<T>& v) const {
            if (reversed) {
                auto it = std::find(v.rbegin(), v.rend(), key);
                if (it != v.rend()) {
                    return std::distance(it, v.rend()) - 1;
                }
            } else {
                auto it = std::find(v.begin(), v.end(), key);
                if (it != v.end()) {
                    return std::distance(v.begin(), it);
                }
            }
            throw std::out_of_range("no data found");
        }
};


// functor compose
template<typename F, typename G>
class compose {
	F f;
	G g;
	public:
		compose(F f, G g): f(f), g(g) { };
		template<typename T>
		auto operator()(T x) const {
			return f(g(x));
		}
};

// generic reduction
template<typename T>
int to_int(T value) {
    return std::to_integer(value);
}

template<>
int to_int<int>(int value) {
    return value;
}

std::vector<float> converter(const std::vector<int>& v, auto lambda) {
    std::vector<float> w;
    int n = v.size(), i = 0;
    for(; i < n; ++i) {
        w.push_back(lambda(v[i]));
    }
    return w;
}

// variadic template
template<typename T>
inline T sum(T t) { return t; };

template<typename T, typename ...P>
inline T sum(T t, P ...p) {
	return t + sum(p...);
};

int main() {
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;
}
