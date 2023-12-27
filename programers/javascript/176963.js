// https://school.programmers.co.kr/learn/courses/30/lessons/176963

function solution(name, yearning, photo) {
    const map = {};
    const n = name.length;

    for (let i = 0; i < n; i++) {
        map[name[i]] = yearning[i];
    }

    var answer = [];
    for (let ph of photo) {
        let score = 0;
        for (let person of ph) {
            if (map[person] !== undefined) {
                score += map[person];
            }
        }

        answer.push(score);
    }

    return answer;
}

solution(
    ["may", "kein", "kain", "radi"],
    [5, 10, 1, 3],
    [
        ["may", "kein", "kain", "radi"],
        ["may", "kein", "brin", "deny"],
        ["kon", "kain", "may", "coni"],
    ]
);
