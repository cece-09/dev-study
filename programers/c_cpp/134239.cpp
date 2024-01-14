// https://school.programmers.co.kr/learn/courses/30/lessons/134239

#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    // 1. 구간합 수열 만들기
    vector<double> presum;
    double sum = 0; // 누적합
    int prev = k;   // 이전 원소
    int n = 0;      // 1이 될때까지의 카운트
    presum.push_back(0);

    do {
        // 두 번째 원소부터 시작
        k = (k % 2) ? (k * 3 + 1) : (k / 2);

        // 이전 원소를 보고 면적 계산
        sum += (k + prev) / 2.0;
        presum.push_back(sum);

        prev = k;
        n++;

    } while(k != 1);

    // 2. 정적분 하기
    int i;
    for(i = 0; i < ranges.size(); ++i) {
        int le = ranges[i][0];
        int ri = ranges[i][1];
        
        if(!le && !ri) {
            // 2.1. 전체 구간에 대한 정적분
            answer.push_back(sum);
            continue;
        }

        // 2.2. 0 또는 음수인 경우 n + ri
        ri = ri <= 0 ? n + ri : ri;

        // 2.3. 시작이 끝보다 클 경우 -1
        if(le > ri) {
            answer.push_back(-1);
            continue;
        }

        // 2.4. le <= ri 인 경우 구간합 연산
        answer.push_back(presum[ri] - presum[le]);
    }

    return answer;
}

int main() {
    int k = 9;
    vector<vector<int>> ranges{{8, 0}};
    solution(k, ranges);
};