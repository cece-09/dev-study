# https://school.programmers.co.kr/learn/courses/30/lessons/147355

def solution(t, p):
    answer = 0
    # t를 순회하면서
    # 더 작은 문자열을 찾음
    n = len(p)
    m = len(t)

    for i in range(m-n+1):
        comp = t[i:i+n]
        print(comp)
        if comp <= p:
            answer += 1

    return answer


t = "500220839878"
p = "7"
solution(t, p)
