// https://school.programmers.co.kr/learn/courses/30/lessons/131701

#include <string>
#include <vector>
// #include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    vector<int> sum(elements);

    for(int m = 0; m < n+1; ++m) { // 각 부분 수열의 길이 m
        if(m == 0 || m == 1)
            continue;
        for(int i = 0; i < n; ++i) { // 길이가 m인 [i, k] 수열의 합을 구합니다.
            int k = (m+i-1) % n;
            sum.push_back(sum[(m-2)*n+i] + sum[k]);
        }
    }

    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end());
    return sum.size();
}

int main() {
    vector<int> elements = {7, 9, 1, 1, 4};
    cout << solution(elements) << endl;
}