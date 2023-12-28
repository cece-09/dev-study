function solution(numbers) {
    // 자신보다 뒤에 있는 숫자 중 자신보다 크면서 가장 가까이 있는 수
    const n = numbers.length;
    const answer = new Array(n).fill(-1);

    // 스택 탑보다 작으면 스택에 넣기
    // 스택 탑보다 크면 스택에서 뽑고 모두 자신으로 설정
    const stack = [];
    stack.push(0);
    let last = 0;

    for (let i = 1; i < n; i++) {
        const top = stack[last];
        if (numbers[top] >= numbers[i]) {
            stack.push(i);
            last++;
        } else {
            while (true) {
                const idx = stack.pop();
                if (idx === undefined) {
                    break;
                }

                if (numbers[idx] >= numbers[i]) {
                    stack.push(idx);
                    break;
                }
                answer[idx] = numbers[i];
                last--;
            }
            stack.push(i);
            last++;
        }
    }

    return answer;
}

const numbers = [9, 1, 5, 3, 6, 2];
console.log(solution(numbers));
