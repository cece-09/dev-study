import math

T = int(input())

for test_case in range(T):
    src, des = map(int, input().split(" "))
    dist = des - src

    pow = int(math.sqrt(dist))
    if (dist == pow ** 2):
        print(f'{pow ** 2 - 1}')
        continue

    if (dist - (pow ** 2) > ((pow + 1) ** 2) - dist):
        pow += 1

    if (pow % 2 == 0):
        print(f'{pow ** 2 - 1}')
    else:
        print(f'{pow ** 2}')
