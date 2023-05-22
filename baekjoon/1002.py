import math

T = int(input())

for _ in range(0, T):
    line = list(map(int, input().split()))
    jx, jy, jr = line[0], line[1], line[2]
    bx, by, br = line[3], line[4], line[5]

    dist = math.sqrt(pow(jx - bx, 2) + pow(jy - by, 2))
    sum = jr + br
    sub = abs(jr - br)

    if (dist == 0 and jr == br):
        print(-1)
    elif ((dist == sum) or (dist == sub)):
        print(1)
    elif (sum > dist > sub):
        print(2)
    else:
        print(0)