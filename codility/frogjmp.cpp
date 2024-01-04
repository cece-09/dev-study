#include <stdio.h>

int solution(int X, int Y, int D) {
  // no jump need
  if (X == Y) return 0;

  return ((Y - X - 1) / D) + 1;
}

int main() {
  int x = 10;
  int y = 85;
  int d = 30;

  int ans = solution(x, y, d);
  printf("%d\n", ans);
  return 0;
}