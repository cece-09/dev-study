# https://school.programmers.co.kr/learn/courses/30/lessons/87946
def solution(k, dungeons):
    answer = 0
    n = len(dungeons)
    
    def dfs(p, visit, cnt, exhaust):
        nonlocal k, answer
        if p == n:
            answer = max(answer, cnt)
            return
        for i in range(n):
            if i in visit:
                continue
            if exhaust < dungeons[i][0]:
                # 탐험 끝
                answer = max(answer, cnt)
                continue
            else:                
                k -= dungeons[i][1]
                dfs(p+1, visit+[i], cnt+1, exhaust-dungeons[i][1])
    
    dfs(0, [], 0, k)
    return answer

k = 80 
dungeons = [[80,20],[50,40],[30,10]]	
print(solution(k, dungeons))