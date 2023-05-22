
T = int(input())

for test_case in range(1, T+1):

    import math

    def isPrime(x):
        if (x % 2 == 0):
            return False
        for i in range(3, int(math.sqrt(x)) + 1, 2):
            if (x % i == 0):
                return False
        return True

    N = int(input())

    for x in range(4 + N, 10 ** 9 + 1):
        # x는 소수가 아님
        if (isPrime(x)):
            continue

        # y = x - N 도 소수가 아님
        y = x - N
        if (not isPrime(y) and y <= 10 ** 9):
            break

    print(f'#{test_case} {x} {y}')
