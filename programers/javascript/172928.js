// https://school.programmers.co.kr/learn/courses/30/lessons/172928

function solution(park, routes) {
    const move = {
        E: [0, 1],
        S: [1, 0],
        W: [0, -1],
        N: [-1, 0],
    };

    let curr = [0, 0];
    let rowObst = new Set();
    let colObst = new Set();

    let row = park.length;
    let col = park[0].length;

    // 시작지점 좌표 찾기
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (park[i][j] === "S") {
                curr[0] = i;
                curr[1] = j;
                continue;
            }

            if (park[i][j] === "X") {
                rowObst.add(i);
                colObst.add(j);
            }
        }
    }

    // 이동
    for (let route of routes) {
        const [op, n] = route.split(" ");

        // 한 칸씩 이동하면서 조건을 만족하는지 확인
        let [nr, nc] = curr;
        let isUpdated = true;
        for (let i = 0; i < n; i++) {
            // n번 반복
            nr += move[op][0];
            nc += move[op][1];

            if (nr >= row || nr < 0 || nc >= col || nc < 0) {
                // 범위 내에 있지 않으면 다음 명령
                isUpdated = false;
                break;
            }

            if (park[nr][nc] === "X") {
                // 장애물을 만나면 다음 명령
                isUpdated = false;
                break;
            }
        }

        if (isUpdated === true) {
            // 이동 가능하면 이동
            curr[0] = nr;
            curr[1] = nc;
        }
    }

    return curr;
}

solution(["OSO", "OOO", "OXO", "OOO"], ["E 2", "S 3", "W 1"]);
