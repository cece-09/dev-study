# https://school.programmers.co.kr/learn/courses/30/lessons/140107

import math

def solution(k, d):
    # 반지름이 d인 원 안의 정수 좌표 개수
    # x축을 따라가면서 점을 카운트
    # x ** 2 + y ** 2 = d ** 2
    answer = 0
    for x in range(0, d+1, k):
        y = math.floor((d ** 2 - x ** 2) ** 0.5)
        print(x, y, (y // k) + 1)
        answer += (y // k) + 1
    
    return answer


k = 2
d = 4
print(solution(2, 4))


    