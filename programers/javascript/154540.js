function solution(maps) {
    const delta = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0],
    ];
    const n = maps.length;
    const m = maps[0].length;
    const visit = Array.from({ length: n }, () => new Array(m).fill(false));

    function bfs(src) {
        const [sr, sc] = src;
        const queue = [];
        queue.push([sr, sc]);

        let total = 0;

        while (true) {
            const front = queue.shift();
            if (front === undefined) {
                break;
            }

            let [r, c] = front;
            total += parseInt(maps[r][c]);
            for (let del of delta) {
                let [nr, nc] = [r + del[0], c + del[1]];
                if (
                    nr < 0 ||
                    nr >= n ||
                    nc < 0 ||
                    nc >= m ||
                    maps[nr][nc] === "X" ||
                    visit[nr][nc] === true
                ) {
                    continue;
                }

                visit[nr][nc] = true;
                queue.push([nr, nc]);
            }
        }

        return total;
    }

    const array = [];
    let cnt = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (maps[i][j] !== "X" && !visit[i][j]) {
                visit[i][j] = true;
                let max_days = bfs([i, j]);
                array.push(max_days);
                cnt++;
            }
        }
    }

    if (cnt === 0) {
        return [-1];
    }

    array.sort((a, b) => a - b);
    return array;
}

const maps = ["X5XX5X", "111111", "XXXXXX", "111111"];
console.log(solution(maps));
