# https://school.programmers.co.kr/learn/courses/30/lessons/142085

from heapq import heappush, heappop

# 내림차순 정렬 구현 위해 우선순위 큐 사용
def solution(n, k, enemy):
    answer = 0
    pq = []
    m = len(enemy)

    for i in range(m):
        n -= enemy[i]                  # 일단 병사 제거
        heappush(pq, -enemy[i])        # max heap
        if n < 0:
            if k > 0:
                front = -heappop(pq)   # max round
                n += front             # 무적권을 사용했다고 간주
                k -= 1                 # 사용 횟수 체크
                answer = i + 1         # 답이 될 수 있는 라운드 체크
            else:
                answer = i             # n < 0 이고 무적권이 남지 않음
                break                  # 게임 종료
        else:
            answer = i + 1             # 답이 될 수 있는 라운드 체크

    return answer


n = 10
k = 2
enemy =  [5, 5, 5, 5, 5]
# n = 7
# k = 3
# enemy = [4, 2, 4, 5, 3, 3, 1]
print(solution(n, k, enemy))
