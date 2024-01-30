# https://school.programmers.co.kr/learn/courses/30/lessons/86052

# 재귀 호출의 최대 깊이를 설정하는 부분
import sys
sys.setrecursionlimit(500000)

# 빛이 이동해서 같은 위치로 돌아오는
# 모든 사이클의 길이 구하기
from collections import defaultdict
def solution(grid):
    n = len(grid)
    m = len(grid[0])
    
    # 현재 칸의 정보를 바탕으로 다음 좌표와 델타를 반환합니다
    def turn(cur, dt, direct):
        if direct == 'S':
            [dr, dc] = dt
        elif sum(dt) > 0:
            dr = dt[0]^1 if direct == 'R' else dt[0]-1
            dc = dt[1]-1 if direct == 'R' else dt[1]^1
        else: 
            dr = -((-dt[0])^1) if direct == 'R' else dt[0]+1
            dc = dt[1]+1 if direct == 'R' else -((-dt[1])^1)
        
        [r, c] = cur # 다음 좌표값
        r += dr ; c += dc
        # 범위를 벗어나는 경우 처리
        if r < 0: r = n-1
        if r > n-1: r = 0
        if c < 0: c = m-1
        if c > m-1: c = 0
        return [(r, c), (dr, dc)]
    
    # 재귀 탐색으로 사이클을 찾습니다
    def dfs(cur, dt, cnt):
        nonlocal src, src_dt
        
        (r, c) = cur
        visit[(r, c, deltas[dt])] = 1
        cnt += 1

        [(nr, nc), ndt] = turn(cur, dt, grid[r][c])
        if (nr, nc) == src and ndt == src_dt: # 사이클 찾음
            cycles.append(cnt)
            return
        if not visit[(nr, nc, deltas[ndt])]:  # 다음 방문
            dfs((nr, nc), ndt, cnt)
    
    deltas = {(0, 1): 'R', (1, 0): 'D', (0, -1): 'L', (-1, 0): 'T'}
    visit = defaultdict(int)
    cycles = []
    for r in range(n):
        for c in range(m):
            for src_dt in deltas.keys():
                src = (r, c) 
                dfs(src, src_dt, 0)
                
    return sorted(cycles)


# grid = ["SL","LR"]	
# grid = ["S"]
grid = ["R","R"]	
print(solution(grid))