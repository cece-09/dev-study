#include <stdio.h>

#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
  // unpaired elem의 수
  int n = A.size();

  sort(A.begin(), A.end());

  for (int i = 0; i < n;) {
    int count = 1;
    int j = i + 1;
    while (j < n && A[i] == A[j]) {
      count++;
      j++;
    }

    if (count % 2) {
      return A[i];
    }
    i = j;
  }

  return 0;
}

int main() {
  vector<int> A;
  A.push_back(9);
  A.push_back(3);
  A.push_back(9);
  A.push_back(3);
  A.push_back(9);
  A.push_back(7);
  A.push_back(9);

  int ans = solution(A);
  printf("%d\n", ans);
  return 0;
}