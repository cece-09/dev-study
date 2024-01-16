#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(vector<int> order) {
    int n = order.size();
    int idx = 0;
    vector<int> stack;

    for(int i = 1; i < n + 1; ++i) {
        stack.push_back(i); // push prevs
        while (stack.size() && stack.back() == order[idx]) {
            stack.pop_back();
            idx += 1; // next order
        }
    }

    return idx;
}

int main() {
    vector<int> order = {3, 5, 4, 2, 1};
    int answer = solution(order);
    cout << answer << endl;
}
