# https://school.programmers.co.kr/learn/courses/30/lessons/72411

from itertools import combinations
from collections import Counter
def solution(orders, courses):
    arr = []
    # 각 주문에 대해 가능한 모든 조합 생성
    for order in orders:
        for course in courses:
            arr += list(combinations(sorted(order), course))

    hash = {k: [2] for k in courses}
    # 조합 카운팅하여 max 조합 선택
    count =  Counter([''.join(v) for v in arr]).items()
    for seq, v in count:
        k = len(seq)
        if hash[k][0] == v:
            hash[k].append(seq)
        elif hash[k][0] < v:
            hash[k] = [v, seq]

    answer = []
    for seq in hash.values():
        answer += seq[1:]
    return sorted(answer)


orders = ["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"]
course = [2,3,5]
print(solution(orders, course))