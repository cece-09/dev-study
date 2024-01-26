
def solution(line):
    inf = float('inf')
    mark, n = [], len(line)
    minx, maxx, miny, maxy = inf, -inf, inf, -inf
    for i in range(n):
        for j in range(i, n):
            if i == j: # 같은 직선인 경우
                continue

            a, b, e, c, d, f = *line[i], *line[j]
            mo = a*d-b*c
            if mo == 0: # 교점이 없음
                continue 

            x, y = (b*f-e*d)/mo, (e*c-a*f)/mo
            if x-int(x) or y-int(y): # 정수가 아님
                continue 

            x, y = int(x), int(y)
            # 값 갱신
            minx, maxx = min(minx, x), max(maxx, x)
            miny, maxy = min(miny, y), max(maxy, y)
            mark.append((x, y))
    # 별 찍기
    answer = [['.' for _ in range(maxx-minx+1)]for _ in range(maxy-miny+1)]
    for x, y in mark:
        answer[maxy-y][x-minx] = '*'
    return [''.join(s) for s in answer]



line = [[2, -1, 4], [-2, -1, 4], [0, -1, 1], [5, -8, -12], [5, 8, 12]]
for sol in solution(line):
    print(sol)