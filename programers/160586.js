// https://school.programmers.co.kr/learn/courses/30/lessons/160586

function min(a, b) {
    return a < b ? a : b;
}

function solution(keymap, targets) {
    // 키 - 눌러야 하는 최소횟수를 매핑해 저장
    const map = {};
    for (let key of keymap) {
        let cnt = 0;
        for (let letter of key) {
            map[letter] = min(map[letter], ++cnt);
        }
    }
    const answer = [];
    for (let target of targets) {
        let cnt = 0;
        for (let letter of target) {
            // 없는 경우
            if (map[letter] === undefined) {
                cnt = -1;
                break;
            } else {
                cnt += map[letter];
            }
        }
        answer.push(cnt);
    }

    return answer;
}

solution(["ABACD", "BCEFD"], ["ABCD", "AABB"]);
solution(["AA"], ["B"]);
