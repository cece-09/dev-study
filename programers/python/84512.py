# https://school.programmers.co.kr/learn/courses/30/lessons/84512

'''
0, 1, 2, 3, 4 로 만들 수 있는
길이 5 이하의 모든 조합을 나열할 때
특정 조합의 인덱스 구하기 문제
'''

def solution(word):
    N = 5
    V = ['A', 'E', 'I', 'O', 'U']
    def comb(k, sub):
        nonlocal cnt, answer
        # k위치의 단어를 선택
        if k == N+1: return
        if sub == word:
            answer = cnt
            return
        # print(cnt, answer, sub)
        cnt += 1
        for i in range(N):
            comb(k+1, sub+V[i])
        
    cnt = 0 ; answer = 0
    comb(0,'')
    return answer

word = "AAAAE"
print(solution(word))