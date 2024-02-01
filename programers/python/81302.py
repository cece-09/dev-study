# https://school.programmers.co.kr/learn/courses/30/lessons/81302


# places가 거리두기를 잘 지키고 있는지 확인
# 모든 응시자에 대해 맨해튼 거리가 2 이하이고
# 사이에 파티션이 없는 케이스를 찾는다.
# 상하좌우 거리 1은 P이면 False이다.
# 상하좌우 거리 2는 P이고 중간에 X가 없으면 False이다
# 대각선 4개 방향은 X가 2개 없으면 False이다.
def solution(places):
    n = 5

    def idx_bound(r, c):
        return (0 <= r < n and 0 <= c < n)

    def check1(r, c):
        for dr, dc in deltas[0]:
            nr, nc = (r+dr, c+dc)
            if idx_bound(nr, nc) and place[nr][nc] == 'P':
                return False
        return True
    
    def check2(r, c):
        for i in range(4):
            dr, dc = deltas[1][i] # 상하좌우 2만큼 떨어진칸
            nr, nc = (r+dr, c+dc)
            cr, cc = deltas[0][i] # 중간 사이칸
            cr, cc = (r+cr, c+cc)
            if (idx_bound(nr, nc) and place[nr][nc] == 'P'
                and idx_bound(cr, cc) and place[cr][cc] != 'X'):
                return False
        return True

    def check3(r, c):
        for dr, dc in deltas[2]:
            nr, nc = (r+dr, c+dc)
            if idx_bound(nr, nc) and place[nr][nc] == 'P':
                for cr, cc in  [(r+dr, c+0), (r+0, c+dc)]:
                    if idx_bound(cr, cc) and place[cr][cc] != 'X':
                        return False
        return True


    deltas = [[(0, 1), (1, 0), (0, -1), (-1, 0)], [(0, 2), (2, 0), (0, -2), (-2, 0)],  [(1, 1), (1, -1), (-1, 1), (-1, -1)]]
    checks = [check1, check2, check3]

    def check(r, c):
        if idx_bound(r, c):
            for chk in checks:
                if not chk(r, c):
                    return False
        return True

    def is_valid(place):
        for r in range(n):
            for c in range(n):
                if place[r][c] == 'P' and not check(r, c):
                    return 0
        return 1
    
    answer = []
    for place in places:
        answer.append(is_valid(place))

    return answer


places = [["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]	
print(solution(places))