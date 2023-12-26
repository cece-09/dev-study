// https://school.programmers.co.kr/learn/courses/30/lessons/160585

function abs(x) {
    if (x < 0) return -1 * x;
    return x;
}

function solution(board) {
    const n = 3;
    const ttt = {};
    const cnt = { o: 0, x: 0 };

    const keys = [
        "row0",
        "row1",
        "row2",
        "col0",
        "col1",
        "col2",
        "dia1",
        "dia2",
    ];

    keys.forEach((key) => (ttt[key] = 0));

    /* count o, x */
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (board[i][j] === ".") continue;
            if (board[i][j] === "O") cnt.o++;
            if (board[i][j] === "X") cnt.x++;
        }
    }

    let winner = null;
    let finished = null;

    /* determine if winner exists */
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            let mark = board[i][j];
            if (mark === ".") {
                continue;
            }

            ttt[`col${j}`] += mark === "O" ? 1 : -1;
            ttt[`row${i}`] += mark === "O" ? 1 : -1;

            let diff = abs(i - j);

            /* diagonal cases */
            if (diff === 0 && i === 1) {
                ttt["dia1"] += mark === "O" ? 1 : -1;
                ttt["dia2"] += mark === "O" ? 1 : -1;
            } else if (diff === 0) {
                ttt["dia1"] += mark === "O" ? 1 : -1;
            } else if (diff === 2) {
                ttt["dia2"] += mark === "O" ? 1 : -1;
            }

            /* check if winner exists */
            if (abs(ttt[`row${i}`]) === 3) {
                finished = ttt[`row${i}`];
            } else if (abs(ttt[`col${j}`]) === 3) {
                finished = ttt[`col${j}`];
            } else if (abs(ttt["dia1"]) === 3) {
                finished = ttt["dia1"];
            } else if (abs(ttt["dia2"]) === 3) {
                finished = ttt["dia2"];
            }

            if (finished === null) {
                /* there's no winner yet */
                continue;
            }

            if (finished > 0) {
                if (winner !== null && winner === "X") {
                    /* o and x can't both win the game */
                    return 0;
                }
                winner = "O";
            } else {
                if (winner !== null && winner === "O") {
                    /* o and x can't both win the game */
                    return 0;
                }
                winner = "X";
            }
        }
    }

    let diff = cnt.o - cnt.x;
    if (diff < 0 || diff > 1) {
        /* order of o, x doesn't match.
         * diff must be either 0 or 1 */
        return 0;
    }

    console.log(winner);

    if (cnt.o + cnt.x === 9 && diff !== 1) {
        /* last one must be o */
        return 0;
    }

    if (diff === 0 && winner === "O") {
        /* the game continued after o won */
        return 0;
    }

    if (diff === 1 && winner === "X") {
        /* the game continued after x won */
        return 0;
    }

    return 1;
}

/**
 * X O X
 * O X O
 * X O O
 */
const tc = ["XOX", "OXO", "XOO"];
console.log(solution(tc));
