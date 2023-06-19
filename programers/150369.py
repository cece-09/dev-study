def get_max(list, idx):
    while (list[idx] == 0):
        if (idx == 0):
            return -1  # index 0부터 1번째 집이므로 -1로 처리
        else:
            idx -= 1
    return idx


def solution(cap, n, deliveries, pickups):
    answer = 0

    num = len(deliveries)
    db, pb = 0, 0   # 배달, 수거 박스
    di, pi = 0, 0   # 배달, 수거해야 하는 최대 인덱스

    # 최대 인덱스 구하기
    di = get_max(deliveries, num-1)
    pi = get_max(pickups, num-1)

    while (di >= 0 or pi >= 0):
        # update the distance
        answer += (max(di, pi) + 1) * 2

        db, pb = 0, 0
        # 용량이 찰 때까지 방문
        while (di >= 0):
            db += deliveries[di]
            if (db > cap):
                deliveries[di] = (db - cap)
                break
            else:
                deliveries[di] = 0
                di -= 1

        while (pi >= 0):
            pb += pickups[pi]
            if (pb > cap):
                pickups[pi] = (pb - cap)
                break
            else:
                pickups[pi] = 0
                pi -= 1

    return answer
