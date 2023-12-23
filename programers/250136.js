// https://school.programmers.co.kr/learn/courses/30/lessons/250136

function dfs(i, j, land, n, m, visited, map, num) {
    const delta = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0],
    ];

    let oil = 0;

    for (let d of delta) {
        let di = i + d[0];
        let dj = j + d[1];

        if (
            di < n &&
            di >= 0 &&
            dj < m &&
            dj >= 0 &&
            !visited[di][dj] &&
            land[di][dj] > 0
        ) {
            map[dj].add(num);
            visited[di][dj] = 1;
            oil += dfs(di, dj, land, n, m, visited, map, num);
        }
    }

    return oil + 1;
}

function solution(land) {
    // 완탐을 통해 각 열마다 뽑을 수 있는
    // 석유량을 더해나감

    n = land.length;
    m = land[0].length;

    let num = 0; // 덩어리 번호
    let answer = 0;

    const keys = Array.from({ length: m }, (_, index) => `${index}`); // 열 키
    const map = Object.fromEntries(keys.map((key) => [key, new Set()]));
    const visited = Array.from({ length: n }, () => Array(m).fill(0));

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (land[i][j] > 0 && !visited[i][j]) {
                visited[i][j] = 1;
                var oils = dfs(i, j, land, n, m, visited, map, num);
                console.log(`덩어리 ${num}: ${oils}`);
                num++;
            }
        }
    }

    console.log(map);
    return answer;
}

solution([
    [0, 0, 0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 1, 1, 0, 0],
    [1, 1, 0, 0, 0, 1, 1, 0],
    [1, 1, 1, 0, 0, 0, 0, 0],
    [1, 1, 1, 0, 0, 0, 1, 1],
]);
