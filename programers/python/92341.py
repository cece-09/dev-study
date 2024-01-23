# https://school.programmers.co.kr/learn/courses/30/lessons/92341

from collections import defaultdict

def time_diff(start, end):
    shour, smin = map(int, start.split(':'))
    ehour, emin = map(int, end.split(':'))
    return (ehour-shour)*60+(emin-smin)

def solution(fees, records):
    answer = []
    ptime = defaultdict(int)
    stack = defaultdict(list)
    [btime, bfee, tunit, tfee] = fees
    for record in records:
        [t, k, _] = record.split(' ')
        if len(stack[k]) == 0:
            # 항상 IN입니다.
            stack[k] = [t]
        else:
            # 항상 OUT입니다.
            top = stack[k].pop()
            ptime[k] += time_diff(top, t)

    for key in stack.keys():
        # OUT이 없는 차량 정리
        if len(stack[key]) > 0:
            top = stack[key].pop()
            ptime[key] += time_diff(top, "23:59")

        print(key, ptime[key])
        # 1. 기본 시간 이하라면 기본 요금 처구
        if ptime[key] <= btime:
            answer.append((key, bfee))
        # 2. 초과한 시간을 단위시간으로 올림
        else:
            extime = ((ptime[key]-btime-1)//tunit)+1
            answer.append((key, extime*tfee+bfee))
    
    answer.sort(key=lambda x: x[0])
    return list(map(lambda x: x[1], answer))



fees = [180, 5000, 10, 600]
records = [
    "05:34 5961 IN",
    "06:00 0000 IN",
    "06:34 0000 OUT",
    "07:59 5961 OUT",
    "07:59 0148 IN",
    "18:59 0000 IN",
    "19:09 0148 OUT",
    "22:59 5961 IN",
    "23:00 5961 OUT"
]
print(solution(fees, records))