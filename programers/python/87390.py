# https://school.programmers.co.kr/learn/courses/30/lessons/87390

def solution(n, _left, _right):
    left = [_left//n+1, _left%n+1]
    right = [_right//n+1, _right%n+1]

    answer = []
    [r, c] = left
    while r != right[0] or c != right[1]:
        print(f"🍀 {r}, {c}")
        answer.append(r if c <= r else c)
        if c == n:
            c = 1
            r += 1
        else:
            c += 1
            
    [r, c] = right
    answer.append(r if c <= r else c)
    return answer

n = 4
left = 7
right = 14
print(solution(n, left, right))