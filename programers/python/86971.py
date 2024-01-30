# https://school.programmers.co.kr/learn/courses/30/lessons/86971

from collections import defaultdict

def solution(n, wires):
    # 모든 전선에 대해 해당 전선을 제외하고
    # 연결했을 때 발생하는 컴포넌트와 해당 컴포넌트의 정점수
    if n == 2:
        return 0

    # 그래프 만들기
    graph = defaultdict(set)
    visit = [0 for _ in range(n+1)]
    for wire in wires:
        graph[wire[0]].add(wire[1])
        graph[wire[1]].add(wire[0])

    # 송전탑 개수의 차이를 구함
    def get_diff(counts):
        if len(counts) == 0: return None
        if len(counts) == 1: return counts[0]
        if len(counts) == 2: return abs(counts[0]-counts[1])

    # 송전탑 개수를 구함
    def dfs(v):
        nonlocal graph, visit, cnt
        for w in graph[v]:
            if visit[w]: continue
            visit[w] = 1 ; cnt += 1
            dfs(w)

    diff = float('inf')
    for wire in wires:
        # 전선 끊기
        graph[wire[0]].remove(wire[1])
        graph[wire[1]].remove(wire[0])
        counts = []
        for v in list(graph.keys()):
            visit[v] = 1 ; cnt = 0
            dfs(v)
            if cnt:
                counts.append(cnt)
        
        if len(counts) > 2: continue
        diff = min(diff, get_diff(counts))
        # 전선 원복
        graph[wire[0]].add(wire[1])
        graph[wire[1]].add(wire[0])
        visit = [0 for _ in range(n+1)]
    
    return diff

n = 9
wires = [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]	
print(solution(n, wires))