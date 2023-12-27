# 두 원 사이의 정수 쌍
# https://school.programmers.co.kr/learn/courses/30/lessons/181187


import math


def solution(r1, r2):
    answer = 0

    # 1사분면에서 x좌표가 1부터 r2-1일 때 가능한 1 이상의 y좌표
    for x in range(1, r2):
        if (x <= r1):
            y1 = math.floor(math.sqrt(r1 ** 2 - x ** 2))
        else:
            y1 = 0
        y2 = math.floor(math.sqrt(r2 ** 2 - x ** 2))
        answer += (y2 - y1)

    # x, y축 위의 가능한 좌표
    answer += (r2 - r1 + 1)
    answer *= 4

    return answer


r1 = 10
r2 = 43
print(solution(r1, r2))
