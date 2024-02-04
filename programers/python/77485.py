# https://school.programmers.co.kr/learn/courses/30/lessons/77485

# 수가 순차 증가하는 행렬에서
# queries의 범위만큼 회전했을 때
# 위치가 바뀐 수 중 가장 작은 수를 배열에 담아라
def solution(rows, columns, queries):
    answer = []
    matrix = [[r*columns+c+1 for c in range(columns)] for r in range(rows)]
    delta = [(0, 1), (1, 0), (0, -1), (-1, 0), (0, 1)] # 순환

    def rotate(query):
        def get_next(r, c):
            nonlocal dt_idx
            dt = delta[dt_idx]
            nr, nc = (r+dt[0], c+dt[1])
            if ((nr == r1 and nc == c2) or
               (nr == r2 and nc == c2) or
               (nr == r2 and nc == c1) or
               (nr == r1 and nc == c1)):
                dt_idx += 1

            return (nr, nc)
        
        dt_idx = 0
        r1, c1, r2, c2 = map(lambda x: x-1, query)
        value = matrix[r1][c1] # 이전 위치의 값
        curr = get_next(r1, c1) ; start = curr
        min_value = value

        while True:
            nr, nc = curr
            tmp = matrix[nr][nc]
            matrix[nr][nc] = value
            value = tmp                   # update value
            min_value = min(min_value, value) # update min num
            curr = get_next(nr, nc)       # update next
            if curr == start: break

        return min_value

    for query in queries: answer.append(rotate(query))
    return answer

rows = 3
columns = 3
queries =[[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]	

print(solution(rows, columns, queries))