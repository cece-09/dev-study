#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void brute_force(int* ans, int* arr, int cnt, int** users, size_t users_rows,
                 int emoticons[], size_t emoticons_len) {
  if (cnt == emoticons_len) {
    /* 선택이 완료된 경우 */
    int joins = 0;
    int profit = 0;

    for (int i = 0; i < users_rows; i++) {
      /* 유저가 지출한 금액을 저장 */
      int expand = 0;
      for (int j = 0; j < emoticons_len; j++) {
        if (arr[j] < users[i][0]) continue;
        expand += emoticons[j] * (100 - arr[j]) / 100;
      }

      /* 만약 구매 금액이 기준 이상이라면 취소 후 플러스 서비스 가입 */
      if (expand >= users[i][1]) {
        joins++;
      } else {
        profit += expand;
      }
    }

    /* 현재까지의 join수보다 많거나
       joins 수가 같고 profit이 많은 경우 갱신 */
    int ans_joins = ans[0];
    int ans_profit = ans[1];
    if (joins > ans_joins || (joins == ans_joins && profit > ans_profit)) {
      ans[0] = joins;
      ans[1] = profit;
    }
    // printf("total profit: %d, joins: %d\n----------------\n", profit, joins);
    return;
  }

  /* 선택이 완료되지 않은 경우 */
  int disc[] = {10, 20, 30, 40};
  for (int i = 0; i < 4; i++) {
    arr[cnt] = disc[i];
    brute_force(ans, arr, cnt + 1, users, users_rows, emoticons, emoticons_len);
  }
}

int* solution(int** users, size_t users_rows, size_t users_cols,
              int emoticons[], size_t emoticons_len) {
  /* 행사 목적을 최대한으로 달성했을 떄의 가입 수와 이모티콘 매출액 저장 */
  int* answer = (int*)malloc(sizeof(int) * 2);
  answer[0] = 0;
  answer[1] = 0;

  /**
   * 모든 이모티콘마다, 할인율 4개를 적용해서 완전탐색
   * malloc-free를 위해 첫 번째 discount는 선택 후 탐색 */
  int* arr;
  int cnt = 0;

  int disc[] = {10, 20, 30, 40};
  for (int i = 0; i < 4; i++) {
    arr = (int*)malloc(sizeof(int) * users_rows);
    arr[cnt] = disc[i];
    brute_force(answer, arr, cnt + 1, users, users_rows, emoticons,
                emoticons_len);
    free(arr);
  }

  return answer;
}

int main() {
  size_t row = 2;
  size_t col = 2;
  size_t len = 2;

  int* emoticons = (int*)malloc(sizeof(int) * len);
  int** users = (int**)malloc(sizeof(int*) * row);
  for (int i = 0; i < row; i++) {
    users[i] = (int*)malloc(sizeof(int) * col);
  }

  users[0][0] = 40;
  users[0][1] = 10000;
  users[1][0] = 25;
  users[1][1] = 10000;

  emoticons[0] = 7000;
  emoticons[1] = 9000;

  int* ans = solution(users, row, col, emoticons, len);
  printf("answer: %d %d\n", *ans, *(ans + 1));

  free(ans);
  for (int i = 0; i < row; i++) {
    free(users[i]);
  }
  free(users);
  free(emoticons);

  return 0;
}