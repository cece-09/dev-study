function solution(maps) {
    const n = maps.length;
    const m = maps[0].length;

    function bfs(src, des) {
        const queue = [];
        const delta = [
            [0, 1],
            [1, 0],
            [0, -1],
            [-1, 0],
        ];
        const visit = Array.from({ length: n }, () => new Array(m).fill(-1));
        queue.push([src[0], src[1], 0]);

        while (true) {
            let front = queue.shift();
            if (front === undefined) break;

            let [r, c, cnt] = front;

            for (let del of delta) {
                let [nr, nc] = [r + del[0], c + del[1]];
                if (
                    nr >= n ||
                    nr < 0 ||
                    nc >= m ||
                    nc < 0 ||
                    maps[nr][nc] === "X"
                ) {
                    continue;
                }

                if (visit[nr][nc] < 0 || visit[nr][nc] > cnt + 1) {
                    visit[nr][nc] = cnt + 1;
                    queue.push([nr, nc, cnt + 1]);
                }
            }
        }

        return visit[des[0]][des[1]];
    }

    const src = [0, 0];
    const des = [0, 0];
    const lev = [0, 0];

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (maps[i][j] === "S") {
                src[0] = i;
                src[1] = j;
            }

            if (maps[i][j] === "E") {
                des[0] = i;
                des[1] = j;
            }

            if (maps[i][j] === "L") {
                lev[0] = i;
                lev[1] = j;
            }
        }
    }

    const toLev = bfs(src, lev);
    if (toLev < 0) {
        return -1;
    }

    const toDes = bfs(lev, des);
    if (toDes < 0) {
        return -1;
    }

    return toLev + toDes;
}

console.log(solution(["SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"]));
console.log(solution(["LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"]));
