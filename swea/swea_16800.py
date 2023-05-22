

T = int(input())

for test_case in range(1, T+1):
    import math

    # 가장 가까운 두 자연수의 곱으로 나타낸다
    N = int(input())
    move = 0

    for i in range(1, int(math.sqrt(N) + 1)):
        if (N % i == 0):
            move = i

    move += int(N / move)

    print(f'#{test_case} {move - 2}')
