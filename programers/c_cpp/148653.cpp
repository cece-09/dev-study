#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
  int answer = 0;

  // 일의자리부터 5 이상일 경우 다음 자릿수에 + 1
  int digit;

  while (storey) {
    digit = storey % 10;

    if (digit > 5 || (digit == 5 && (storey / 10) % 10 >= 5)) {
      answer += (10 - digit);
      storey += (10 - digit);
    } else {
      answer += digit;
    }

    storey /= 10;
  }

  return answer;
}

int main() {
  int tc = 95;  // 5 + 1
  int ans = solution(tc);
  printf("answer: %d\n", ans);
  return 0;
}