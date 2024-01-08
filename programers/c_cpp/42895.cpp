#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef set<int>::iterator iter;

int solution(int N, int number) {
  int multi = 1;
  int unit = 10;
  // dp[i] => N을 i+1번 사용해 만들 수 있는 수의 집합
  vector<set<int> > dp(8);

  for (int i = 0; i < 8; i++) {
    // create N, NN, NNN, ...
    int num = N * multi;
    multi += unit;
    unit *= 10;

    dp[i].insert(num);
    for (int j = 0; j < i; j++) {
      for (iter p = dp[j].begin(); p != dp[j].end(); p++) {
        for (iter q = dp[i - j - 1].begin(); q != dp[i - j - 1].end(); q++) {
          dp[i].insert((*p) + (*q));
          dp[i].insert((*p) - (*q));
          dp[i].insert((*p) * (*q));
          dp[i].insert((*p) / (*q));
        }
      }
    }

    if (dp[i].find(number) != dp[i].end()) {
      return i + 1;
    }
  }

  return -1;
}

int main() {
  int N = 6;
  int number = 5;
  int answer = solution(N, number);
  cout << answer << endl;

  return 0;
}