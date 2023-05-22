# Gold3
# TopologicalSorting & DP

from collections import deque

T = int(input())

for i in range(T):
    N, K = map(int, input().split())

    time = [0] + list(map(int, input().split()))
    result = time.copy()

    degree = [0] * (N + 1)
    graph = [[] for _ in range(N+1)]
    queue = deque([i+1 for i in range(N)])

    # graph as adjacency list
    for _ in range(K):
        src, des = map(int, input().split())
        graph[src].append(des)
        degree[des] += 1

    # topological sort
    while(queue):
        v = queue.popleft()
        if not degree[v]:
            for i in graph[v]:
                result[i] = max(result[i], result[v] + time[i])
                degree[i] -= 1
        else:
            queue.append(v)

    W = int(input())
    print(result[W])
