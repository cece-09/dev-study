#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>

using namespace std;

// 디버깅용 출력 함수
void show_deque(const deque<int> dq) {
    for(auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

// 정방향 또는 역방향으로 벡터를 순회하며
// 중복되지 않는 토핑 가짓수를 셉니다
void count_unique_topping(
    const vector<int>& topping, // topping
    deque<int>& vec,            // result
    int n, bool reverse = false // number, direction
) {
    set<int> tmp;
    int cnt = 0;
    
    int curr = (!reverse) ? 0 : n-1;
    int last = (!reverse) ? n : -1;
    
    for(; curr != last; (!reverse) ? ++curr : --curr) {
        // 중복값이 아닌 경우
        if(tmp.empty() || tmp.find(topping[curr]) == tmp.end()) {
            tmp.insert(topping[curr]);
            ++cnt;
        }
        
        if(reverse) {
            vec.push_front(cnt);
        } else {
            vec.push_back(cnt);    
        }
    }
}

int solution(vector<int> topping) {
    int answer = 0;
    // 토핑의 가짓수가 동일하도록 롤케이크를 나누는 방법의 수
    
    int n = topping.size();
    
    deque<int> le;
    deque<int> ri;
    
    // 양쪽에서 순회하면서 토핑 가짓수 세기
    count_unique_topping(topping, le, n);
    count_unique_topping(topping, ri, n, true);
    
    // show_deque(le);
    // show_deque(ri);
    
    // 각 큐를 순회하면서 le[i] == ri[i+1] 인 인덱스 찾기
    for(int i = 0; i < n; i++) {
        if(le[i] == ri[i+1]) {
            answer ++;
        }
    }
    
    return answer;
}