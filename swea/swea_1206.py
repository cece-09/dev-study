
T = 10

for test_case in range(1, T+1):
    N = int(input())  # 건물의 개수
    height = list(map(int, input().split()))  # 각 건물의 높이
    view = height.copy()  # 가능한 최대 수를 업데이트

    for i in range(2, N-2):

        if (height[i] > height[i+1]):
            view[i+1] = 0
            view[i] = min(view[i], height[i] - height[i+1])
        else:
            view[i] = 0
            view[i+1] = min(view[i+1], height[i+1] - height[i])

        if (height[i] > height[i+2]):
            view[i+2] = 0
            view[i] = min(view[i], height[i] - height[i+2])
        else:
            view[i] = 0
            view[i+2] = min(view[i+2], height[i+2] - height[i])

    print(f'#{test_case} {sum(view)}')
