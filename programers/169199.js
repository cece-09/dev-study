function solution(board) {
    const n = board.length;
    const m = board[0].length;
    const direct = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0],
    ];

    function min(a, b) {
        return a < b ? a : b;
    }

    function move(r, c, dir) {
        let [nr, nc] = [r, c];
        let [pr, pc] = [r, c];
        while (
            nr < n &&
            nr >= 0 &&
            nc < m &&
            nc >= 0 &&
            board[nr][nc] !== "D"
        ) {
            pr = nr;
            pc = nc;

            nr += dir[0];
            nc += dir[1];
        }

        return [pr, pc];
    }

    const queue = [];
    const src = [0, 0];
    const des = [0, 0];
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (board[i][j] === "R") {
                src[0] = i;
                src[1] = j;
            }

            if (board[i][j] === "G") {
                des[0] = i;
                des[1] = j;
            }
        }
    }

    const visit = Array.from({ length: n }, () => new Array(m).fill(-1));
    // 좌표 + 이동해야 하는 횟수를 큐에 저장
    queue.push([src[0], src[1], 0]);

    while (true) {
        let front = queue.shift();
        if (front === undefined) break;

        let [r, c, cnt] = front;
        for (dir of direct) {
            let [nr, nc] = move(r, c, dir);

            // 아직 방문 전이거나, 이동횟수가 더 적다면 갱신
            if (visit[nr][nc] < 0 || visit[nr][nc] > cnt + 1) {
                queue.push([nr, nc, cnt + 1]);
                visit[nr][nc] = cnt + 1;
            }
        }
    }

    return visit[des[0]][des[1]];
}

// const board = ["...D..R", ".D.G...", "....D.D", "D....D.", "..D...."];
const board = [".D.R", "....", ".G..", "...D"];
console.log(solution(board));
