from itertools import combinations
import math

T = int(input())

for _ in range(T):
    N = int(input())
    P = [(0, 0) for _ in range(N)]
    xsum, ysum = 0, 0

    for i in range(N):
        x, y = map(int, input().split())
        xsum += x
        ysum += y
        P[i] = (x,y)

    cases = list(combinations(P, N // 2))
    min = -1

    for case in cases:  # NC2
        vsum = [xsum, ysum]
        
        for point in case: # N//2
            vsum[0] -= (2 * point[0])
            vsum[1] -= (2 * point[1])
        
        length = math.sqrt(pow(vsum[0], 2) + pow(vsum[1], 2))

        if (length < min or min < 0):
            min = length

    print(min)
