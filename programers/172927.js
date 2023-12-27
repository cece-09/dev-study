// https://school.programmers.co.kr/learn/courses/30/lessons/172927

function min(a, b) {
    return a < b ? a : b;
}

function sum(array) {
    let rtn = 0;
    array.map((each) => (rtn += each));
    return rtn;
}

function solution(picks, minerals) {
    const n = minerals.length;
    const exhaust = [
        [1, 1, 1],
        [5, 1, 1],
        [25, 5, 1],
    ];

    /* count minerals per 5 */
    let length = min(sum(picks) * 5, n);
    let tmp = { dia: 0, iro: 0, sto: 0 };
    let count = [];

    for (let i = 0; i < length; i++) {
        let mineral = minerals[i];
        tmp[mineral.substring(0, 3)]++;
        if ((i + 1) % 5 === 0 || i === n - 1) {
            count.push(tmp);
            tmp = { dia: 0, iro: 0, sto: 0 };
        }
    }

    /* sort in order of dia, iron, stone */
    count.sort((a, b) => {
        if (a.dia !== b.dia) return b.dia - a.dia;
        if (a.iro !== b.iro) return b.iro - a.iro;
        return b.sto - a.sto;
    });

    let answer = 0;
    for (let { dia, iro, sto } of count) {
        for (let j = 0; j < 3; j++) {
            if (picks[j]) {
                picks[j]--;
                answer +=
                    dia * exhaust[j][0] +
                    iro * exhaust[j][1] +
                    sto * exhaust[j][2];
                break;
            }
        }
    }

    return answer;
}

const picks = [0, 1, 1];
const minerals = [
    "diamond",
    "diamond",
    "diamond",
    "diamond",
    "diamond",
    "iron",
    "iron",
    "iron",
    "iron",
    "iron",
    "diamond",
];
console.log(solution(picks, minerals));
