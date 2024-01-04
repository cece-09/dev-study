#include <iostream>
#include <vector>

using namespace std;
int abs(int x) {
  // 정수 x의 절댓값 반환
  return x < 0 ? -x : x;
}

int solution(vector<int> &A) {
  // 각 부분수열의 합의 차가 최소가 되도록
  // 배열을 나누는 인덱스값 찾기
  int left = 0;
  int righ = 0;

  int n = A.size();
  for (int i = 0; i < n; i++) {
    righ += A[i];
  }

  int answ = 0;
  int diff = 0;
  for (int i = 1; i < n; i++) {
    left += A[i - 1];
    righ -= A[i - 1];

    int tmp = abs(left - righ);
    if (tmp > diff) {
      diff = tmp;
      answ = i;
    }
  }

  return answ;
}

int main() {}