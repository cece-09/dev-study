# https://school.programmers.co.kr/learn/courses/30/lessons/76502

from collections import deque

# 괄호 문자열을 회전시켰을 때
# 올바른 괄호 문자열이 되게 하는 x의 개수
def solution(s):
    bracket = {']': '[', ')': '(', '}': '{'}
    def is_valid(string):
        stack = []
        for c in string:
            if c in bracket.values():
                stack.append(c)
            elif stack and stack[-1] == bracket[c]:
                stack.pop()
            else:
                return False
        if stack:
            return False
        return True
    
    def shift(string: deque):
        left = string.popleft()
        string.append(left)
    
    string = deque(s)
    n = len(string)
    cnt = 0
    for _ in range(n):
        cnt += is_valid(string)
        shift(string)

    return cnt

s = "[](){}"	
print(solution(s))