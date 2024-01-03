// https://school.programmers.co.kr/learn/courses/30/lessons/154538

function solution(x, y, n) {
    let answer = -1;

    const queue = [{ num: y, tried: 0 }];
    while (true) {
        const front = queue.shift();
        if (front === undefined) break;
        const { num, tried } = front;

        if (num === x) {
            answer = tried;
            break;
        }

        if (num % 2 === 0) {
            queue.push({ num: num / 2, tried: tried + 1 });
        }
        if (num % 3 === 0) {
            queue.push({ num: num / 3, tried: tried + 1 });
        }
        if (num - n >= x) {
            queue.push({ num: num - n, tried: tried + 1 });
        }
    }

    return answer;
}

const [x, y, n] = [10, 40, 5];
console.log(solution(x, y, n));
