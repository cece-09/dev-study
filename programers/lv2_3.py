def solution(sequence, k):
    answer = []
    sq = sequence

    l = 0
    r = 0
    sum = sq[0]

    while (True):
        if (sum < k):
            if (r == len(sq)-1):
                break
            r += 1
            sum += sq[r]
        elif (sum > k):
            sum -= sq[l]
            l += 1
        if (sum == k):
            if (len(answer) == 0
                or answer[0] > l
                    or answer[1]-answer[0] > r-l):
                answer = [l, r]
            # move to next
            if (r + 1 < len(sq)):
                r += 1
                sum += sq[r]
            else:
                sum -= sq[r]
                l += 1

    print(answer)
    return answer


sequence = [2, 2, 2, 2, 2]
k = 6
print(solution(sequence, k))


def solution(sequence, k):
    answer = []
    sq = sequence

    l = 0
    r = 0
    sum = sq[0]

    while (True):
        # sum이 k보다 작음
        if (sum < k):
            # r이 마지막 위치인 경우 escape
            if (r == len(sq)-1):
                break
            r += 1
            sum += sq[r]

        # sum이 k보다 큼
        elif (sum > k):
            sum -= sq[l]
            l += 1

        # 연산 후 sum == k 인지 검사
        # 길이가 짧은 경우에만 update
        if (sum == k):
            if (len(answer) == 0
                or answer[0] > l
                    or answer[1]-answer[0] > r-l):
                answer = [l, r]
            # move to next
            if (r + 1 < len(sq)):
                r += 1
                sum += sq[r]
            else:
                sum -= sq[r]
                l += 1

    return answer
