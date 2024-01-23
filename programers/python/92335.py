# https://school.programmers.co.kr/learn/courses/30/lessons/92335

def prime(str):
    if str == '' or int(str) == 1:
        return False
    k = int(str)
    for i in range(2, int(k**0.5)+1):
        if not (k % i):
            return False
    return True

def solution(n, k):
    answer = 0
    stack = []
    prev = ''
    def count_prime():
        nonlocal prev, stack, answer
        while stack:
            prev = stack.pop() + prev
        answer += prime(prev)
        prev = ''
    
    # n을 k진수로 바꾸었을 때
    # 변환된 수 아래 아래 조건에 맞는 소수의 개수
    num = ''
    while n:
        num = f"{n % k}" + num
        n //= k
    
    # num을 순회하면서 0이 아니면 스택에 담습니다
    # 0이면 이전 스택을 pop해서 소수인지 확인합니다
    for d in num:
        if d == '0' and stack:
            count_prime()
        elif d != '0':
            stack.append(d)
    
    count_prime()
    return answer


n = 1000000	
k = 10
print(solution(n, k))