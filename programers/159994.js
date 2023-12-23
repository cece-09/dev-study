// https://school.programmers.co.kr/learn/courses/30/lessons/159994

function solution(cards1, cards2, goal) {
    let i = 0; // cards1 pointer
    let j = 0; // cards2 pointer

    let n = cards1.length;
    let m = cards2.length;

    for (let word of goal) {
        if (i < n && cards1[i] === word) {
            i++;
            continue;
        }

        if (j < m && cards2[j] === word) {
            j++;
            continue;
        }

        return "No";
    }
    return "Yes";
}

solution(
    ["i", "drink", "water"],
    ["want", "to"],
    ["i", "want", "to", "drink", "water"]
);

solution(
    ["i", "water", "drink"],
    ["want", "to"],
    ["i", "want", "to", "drink", "water"]
);
