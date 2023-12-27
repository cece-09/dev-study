// https://school.programmers.co.kr/learn/courses/30/lessons/161990

function min(a, b) {
    return a < b ? a : b;
}
function max(a, b) {
    return a < b ? b : a;
}

function solution(wallpaper) {
    let lux = Number.MAX_SAFE_INTEGER;
    let luy = Number.MAX_SAFE_INTEGER;
    let rdx = 0;
    let rdy = 0;

    const row = wallpaper.length;
    const col = wallpaper[0].length;

    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (wallpaper[i][j] === "#") {
                // 파일이 있는 경우 끝값 갱신
                lux = min(lux, i);
                luy = min(luy, j);
                rdx = max(rdx, i + 1);
                rdy = max(rdy, j + 1);
            }
        }
    }
    return [lux, luy, rdx, rdy];
}

solution([
    "..........",
    ".....#....",
    "......##..",
    "...##.....",
    "....#.....",
]);
