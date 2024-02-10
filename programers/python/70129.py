# https://school.programmers.co.kr/learn/courses/30/lessons/70129

# x의 모든 0을 제거
# x의 길이 c를 2진법으로 표현한 문자열로 변경
# 한다고 했을 때 이진 변환의 횟수와
# 변환 과정에서 제거된 0의 개수
from collections import Counter
def solution(s):
    answer = [0, 0]
    
    def toBinary(c):
        bin = ''
        while c:
            bin += f"{c % 2}"
            c //= 2
        return bin

    while s != '1':
        # 1. 0 제거
        count = Counter(s)
        answer[1] += count['0']
        s = s.replace('0', '')
        # 2. 길이 c를 2진 변환
        s = toBinary(len(s))
        answer[0] += 1
        
    return answer

s = "01110"	
print(solution(s))