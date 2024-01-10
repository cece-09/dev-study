# https://school.programmers.co.kr/learn/courses/30/lessons/138476

from collections import Counter

def solution(k, tangerine):
    # 서로 다른 종류를 최소화하여 k개를 고를 때, 종류의 수
    cnt = Counter(tangerine)
    # count 기준 내림차순 정렬
    kinds = list(cnt.keys())
    kinds.sort(key=lambda x: -cnt[x])

    answer = 0
    for kind in kinds:
        k -= cnt[kind]
        answer += 1
        if k <= 0: # 현재 종류까지 담음
            break
    return answer
    

k = 2
tangerine = [1, 1, 1, 1, 2, 2, 2, 3]
print(solution(k, tangerine))
