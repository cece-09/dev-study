# https://school.programmers.co.kr/learn/courses/30/lessons/147354

def solution(data, col, row_begin, row_end):
    answer = -1
    # 테이블의 튜플을 col번째 컬럼의 값을 기준으로 오름차순 정렬
    # 값이 동일할 경우 첫 번째 컬럼 기준으로 내림차순 정렬
    data.sort(key=lambda tup: (tup[col-1], -tup[0]))

    # S_i = i행 튜플의 컬럼 값을 i로 나눈 나머지의 합
    for i in range(row_begin-1, row_end):
        s = sum(list(map(lambda x: x % (i+1), data[i])))
        # b < S_i < e 인 모든 S_i를 누적해
        # bitwise XOR해서 반환
        if answer < 0:
            answer = s
        else:
            answer ^= s

    return answer


data = [[2, 2, 6], [1, 5, 10], [4, 2, 9], [3, 8, 3]]
col = 2
row_begin = 2
row_end = 3

print(solution(data, col, row_begin, row_end))
