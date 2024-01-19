#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void show_vector(const vector<T>& v) {
    cout << "{";
    int n = v.size();
    for(int i = 0; i < n; ++i)
        cout << v[i] << (i == n-1 ? "" : ", ");
    cout << "}" << endl;
}

template <typename T>
inline void extend(vector<T>& v, const vector<T> w) {
    if(w.empty())
        return;
    v.reserve(v.size() + distance(w.begin(), w.end()));
    v.insert(v.end(), w.begin(), w.end());
}

template <typename T>
inline void extend(vector<T>& v, T e) {
    v.push_back(e);
}

template <typename T>
vector<T> quicksort(vector<T>& v) {
    if(v.size() < 2)
        return v;
    
    int idx = 0;
    T pivot = v[idx];
    vector<T> left, right;

    for(int i = idx+1; i < v.size(); ++i) {
        if(v[i] < pivot)
            left.push_back(v[i]);
        else
            right.push_back(v[i]);
    }

    left = quicksort(left);
    right = quicksort(right);

    extend(left, pivot);
    extend(left, right);
    return left;
}

int main() {
    vector<int> arr = {10, 2, 44, -5, 11};
    show_vector<int>(quicksort<int>(arr));   
}