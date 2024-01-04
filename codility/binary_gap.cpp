#include <stdio.h>

int solution(int N) {
  int cur_gap = 0;
  int max_gap = 0;
  int check = false;

  while (N) {
    if (N % 2 == 0 && check) {
      cur_gap++;
    } else if (N % 2 && !check) {
      check = true;
    } else if (N % 2) {
      max_gap = cur_gap > max_gap ? cur_gap : max_gap;
      cur_gap = 0;
    }

    N /= 2;
  }

  return max_gap;
}

int main() {
  int ans = solution(15);
  printf("%d\n", ans);
  return 0;
}