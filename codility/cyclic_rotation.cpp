#include <stdio.h>

#include <vector>

using namespace std;
vector<int> solution(vector<int> &A, int K) {
  // A배열을 오른쪽으로 K번 shift
  int n = A.size();
  vector<int> B(n, 0);

  for (int i = 0; i < n; i++) {
    int idx = i + (K % n);
    if (idx >= n) {
      idx -= n;
    }
    B[idx] = A[i];
  }
  return B;
}

int main() {
  vector<int> A;
  A.push_back(3);
  A.push_back(8);
  A.push_back(9);
  A.push_back(7);
  A.push_back(6);
  int K = 3;

  vector<int> ans = solution(A, K);
  int n = ans.size();
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");

  return 0;
}