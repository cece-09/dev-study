function solution(weights) {
    const dict = {};

    for (let weight of weights) {
        if (dict[weight] === undefined) {
            dict[weight] = 1;
        } else {
            dict[weight]++;
        }
    }

    weights.sort((a, b) => a - b);
    let answer = 0;

    for (let weight of weights) {
        // 1:1
        if (dict[weight] > 1) {
            answer += dict[weight] - 1;
        }

        // 3:2
        if (dict[weight * (3 / 2)] !== undefined) {
            answer += dict[weight * (3 / 2)];
        }

        // 2:3
        if (dict[weight * 2] !== undefined) {
            answer += dict[weight * 2];
        }

        // 4:3
        if (dict[weight * (4 / 3)] !== undefined) {
            answer += dict[weight * (4 / 3)];
        }

        dict[weight]--;
    }

    return answer;
}

const weights = [100, 100, 100, 150, 150, 200, 300];
console.log(solution(weights));
