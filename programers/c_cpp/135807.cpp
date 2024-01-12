// https://school.programmers.co.kr/learn/courses/30/lessons/135807?language=cpp

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int solution(vector<int> A, vector<int> B) {
    // 각 리스트의 최대공약수 찾기
    int n = A.size();

    int gcdA = A[0];
    int gcdB = B[0];

    for(int i = 1; i < n; i++) {
        gcdA = gcd(min(gcdA, A[i]), max(gcdA, A[i]));
        gcdB = gcd(min(gcdB, B[i]), max(gcdB, B[i]));
    }

    cout << gcdA << " & " << gcdB << endl;

    // 각 최대공약수와 각 상대 리스트의 원소를 나눈 나머지가
    // 모두 0이 아닐 때, A, B 최대공약수 중 더 큰 값을 반환
    bool chkA = true;
    bool chkB = true;
    for(int i = 0; i < n; i++) {
        if(A[i] % gcdB == 0) {
            chkB = false;
        }
        if(B[i] % gcdA == 0) {
            chkA = false;
        }
        if(!chkA && !chkB) {
            // 정답이 없는 경우
            return 0;
        }
    }

    if(chkA && chkB) {
        // 최댓값을 반환
        return max(gcdA, gcdB);
    }

    return chkA ? gcdA : gcdB;
}

int main() {
    vector<int> A;
    vector<int> B;

    A.push_back(10);
    A.push_back(17);
    B.push_back(5);
    B.push_back(20);

    int ans = solution(A, B);
    cout << ans << endl;

    return 0;
}