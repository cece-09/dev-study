function solution(m, n, startX, startY, balls) {
    const answer = [];
    const [sx, sy] = [startX, startY];

    for (let [dx, dy] of balls) {
        // (sx, sy) 대칭이동
        // (-sx, sy), (sx, -sy), (sx, 2*n - sy), (2*m - sx, sy)
        const t = (dx - sx) ** 2 + (dy - 2 * n + sy) ** 2;
        const b = (dx - sx) ** 2 + (dy + sy) ** 2;
        const l = (dx + sx) ** 2 + (dy - sy) ** 2;
        const r = (dx - 2 * m + sx) ** 2 + (dy - sy) ** 2;

        if (dx === sx) {
            // 같은 x축에 있는 경우
            if (dy > sy) {
                answer.push(Math.min(b, l, r));
            } else {
                answer.push(Math.min(t, l, r));
            }
        } else if (dy === sy) {
            if (dx > sx) {
                answer.push(Math.min(b, t, l));
            } else {
                answer.push(Math.min(b, t, r));
            }
        } else {
            answer.push(Math.min(t, b, l, r));
        }
    }

    return answer;
}

const m = 10;
const n = 10;
const startX = 3;
const startY = 7;
const balls = [
    [7, 7],
    [2, 7],
    [7, 3],
];

console.log(solution(m, n, startX, startY, balls));
