// https://school.programmers.co.kr/learn/courses/30/lessons/155652

function solution(s, skip, index) {
    let answer = [];
    let n = s.length;
    const skipSet = new Set();
    const first = "a".charCodeAt(0);
    const last = "z".charCodeAt(0);

    // skip을 set에 추가
    for (let sk of skip) {
        skipSet.add(sk);
    }

    for (let i = 0; i < n; i++) {
        let j = 1; // 다음 변환할 위치
        let cnt = 0; // 전체 개수
        let numeric = s[i].charCodeAt(0);
        let encoded = String.fromCharCode(numeric + j);
        while (cnt < index) {
            if (numeric + j > last) {
                // 범위를 벗어날 경우 다시 a부터 되돌리기
                j = 0;
                numeric = first;
                encoded = String.fromCharCode(numeric);
            } else {
                // index만큼 뒤에 있는 문자 찾기
                encoded = String.fromCharCode(numeric + j);
            }

            // 만약 스킵 문자라면 스킵
            if (skipSet.has(encoded)) {
                j++;
                continue;
            }
            j++;
            cnt++;
        }

        answer.push(encoded);
    }

    console.log(answer.join(""));
    return answer.join("");
}

solution("bcdefghijklmnopqrstuvwxyz", "a", 1);
