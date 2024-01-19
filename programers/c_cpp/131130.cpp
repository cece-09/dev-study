// https://school.programmers.co.kr/learn/courses/30/lessons/131130

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int solution(vector<int>);

int main() {
    //                   1  2  3  4  5  6  7  8
    vector<int> cards = {8, 6, 3, 7, 2, 5, 1, 4};
    cout << solution(cards) << endl;
}

/**
 * vec안에서 접근할 수 있는
 * 최대 깊이의 unvisited node 수
*/
int proceed(
    const vector<int> vec,
    vector<int>& vis,
    int idx
) {
    if(vis[idx])
        return 0;

    vis[idx] = 1;
    return proceed(vec, vis, vec[idx]-1) + 1;
}

/**
 * first 상자의 size를 먼저 정합니다. 해당
 * 상자를 택했을 때 second 상자를 택합니다.
 * first - second 순서가 고려되어야 합니다.
*/
int solution(vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    vector<int> visit(n);

    int first, second;
    // 첫 번째 상자 그룹 시작 인덱스
    for(int i = 0; i < n; ++i) { 
        first = proceed(cards, visit, i);
        second = 0;
        // 두 번째 상자 그룹 시작 인덱스
        for(int j = 0; j < n && !visit[j]; ++j) {
            second = max(proceed(cards, visit, j), second);
        }
        answer = max(answer, first * second); // 게임 점수 최댓값 구하기
        fill(visit.begin(), visit.end(), 0);  // visit 초기화
    }
    return answer;
}