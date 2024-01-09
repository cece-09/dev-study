# https://school.programmers.co.kr/learn/courses/30/lessons/142085

# 적의 수가 가장 많은 라운드에 무적권을 사용해야 유리
# 순회하면서 스택에 넣고 정렬
# 만약 스택 길이가 k이고, 병사가 0명이면 종료
def solution(n, k, enemy):
    m = len(enemy)
    stack = []
    tmp = []
    cnt = 1
    isover = 0

    stack.append(enemy[0])

    for i in range(1, m):
        if n <= 0:
            isover = 1
            i -= 1  # 이전 라운드까지 방어 성공
            break

        print(f"{i}: {enemy[i]}")
        if enemy[i] < stack[-1]:
            if cnt < k:  # 작고 count < k이면 쌓고
                stack.append(enemy[i])
                cnt += 1
            else:  # 작고 count >= k이면 누적합
                n -= enemy[i]
            print(stack, n)
            continue

        # 크면 pop
        while stack and enemy[i] > stack[-1]:
            tmp.append(stack.pop())
            cnt -= 1

        stack.append(enemy[i])
        cnt += 1

        while tmp:
            if cnt < k:
                stack.append(tmp.pop())
                cnt += 1
            else:
                n -= tmp.pop()
        print(stack, n)

    return i if isover else i+1


# n = 7
# k = 3
# enemy = [4, 2, 4, 5, 3, 3, 1]
n = 2
k = 4
enemy = [3, 3, 3, 3]
print(solution(n, k, enemy))
