# 요격 시스템
# https://school.programmers.co.kr/learn/courses/30/lessons/181188


def intersect(x, y):
    if (x[1] > y[0] and x[0] < y[1]):
        return [max(x[0], y[0]), min(x[1], y[1])]
    else:
        return -1


def solution(targets):
    answer = 1

    targets.sort()
    pivot = targets[0]

    for i in range(1, len(targets)):
        inter = intersect(pivot, targets[i])
        if (inter != -1):
            pivot = inter
        else:
            answer += 1
            pivot = targets[i]

    return answer
