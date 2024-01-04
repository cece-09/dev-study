#include <stdio.h>

#include <vector>

using namespace std;
int solution(vector<int> &A) {
  int n = A.size();

  long long max = 0;  // 오버플로우 방지.. 조심
  long long cur_sum = 0;
  for (int i = 0; i < n; i++) {
    max = A[i] > max ? A[i] : max;
    cur_sum += A[i];
  }

  long long tar_sum = (max * (max + 1)) / 2;
  if (tar_sum == cur_sum) {
    return max + 1;
  }

  return tar_sum - cur_sum;
}

int main() {
  int arr[] = {2, 3, 1, 5};
  int len = 4;
  vector<int> A;

  for (int i = 0; i < len; i++) {
    A.push_back(arr[i]);
  }

  int ans = solution(A);
  printf("answer: %d\n", ans);

  return 0;
}