# https://school.programmers.co.kr/learn/courses/30/lessons/250125

def solution(board, h, w):
    n = len(board)
    count = 0

    dh = [0, 1, -1, 0]
    dw = [1, 0, 0, -1]

    for i in range(4):
        h_check = h+dh[i]
        w_check = w+dw[i]
        if 0 <= h_check < n and 0 <= w_check < n:
            if board[h][w] == board[h_check][w_check]:
                count += 1
    return count


tc = [
    {
        "board": [["blue", "red", "orange", "red"], ["red", "red", "blue", "orange"], ["blue", "orange", "red", "red"], ["orange", "orange", "red", "blue"]],
        "h": 1,
        "w": 1,
    }
]
print(solution(tc[0]['board'], tc[0]['h'], tc[0]['w']))
