// https://school.programmers.co.kr/learn/courses/30/lessons/161989
function solution(n, m, section) {
    // section 배열을 돌면서
    // 색을 칠하면서 카운트를 올림

    let cnt = 0;
    let prev = 0;
    let colored = 0;
    for (let sec of section) {
        if (prev === 0) {
            // 첫 번째 칠
            colored++;
            prev = sec;
            cnt++;
            continue;
        }

        colored += sec - prev;
        if (colored > m) {
            cnt++;
            colored = 1;
        }

        prev = sec;
    }

    return cnt;
}

solution(8, 4, [2, 3, 6]);
solution(5, 4, [1, 3]);
solution(4, 1, [1, 2, 3, 4]);
