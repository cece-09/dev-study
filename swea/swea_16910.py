# 원 안의 점
import math

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.

for test_case in range(1, T + 1):
    N = int(input())
    cnt = 0

    # 1사분면 위의 점
    for x in range(N):
        y = math.sqrt(pow(N, 2) - pow(x, 2))
        cnt += int(y)

    cnt *= 4
    cnt += 1  # 원점

    print(f'#{test_case} {cnt}')
