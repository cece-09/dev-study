# https://school.programmers.co.kr/learn/courses/30/lessons/92342


def solution(n, info):
    m = 10 # 리스트 길이
    apeach = info
    max_diff = 0 ; max_list = [-1]

    # 어피치와 라이언의 점수 차 계산
    def get_diff(apeach, ryan):
        ap, ry = [0, 0]
        for i in range(m+1):
            if apeach[i] == ryan[i] == 0:
                continue
            if apeach[i] >= ryan[i]:
                ap += (m-i)
            else:
                ry += (m-i)
        return ry - ap

    # 완전탐색
    def dfs(arrow, idx, ryan):
        nonlocal max_diff, max_list
        # 화살을 다 소진
        if arrow == 0:
            diff = get_diff(apeach, ryan)
            if diff > max_diff:
                max_diff = diff
                max_list = ryan
            return
        
        # 작은 점수 화살부터 쏘기
        for k in range(idx, m+1):
            i = m-k
            new_ryan = ryan[:]
            if apeach[i] < arrow:
                new_ryan[i] = apeach[i]+1
                dfs(arrow-new_ryan[i], k+1, new_ryan)
            else:
                new_ryan[m] += arrow
                dfs(0, k+1, new_ryan)
        
        new_ryan = ryan[:]
        new_ryan[m] += arrow
        dfs(0, -1, new_ryan)
    
    dfs(n, 0, [0 for _ in range(m+1)])
    return max_list

n = 10
info =  [0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3]
print(solution(n, info))