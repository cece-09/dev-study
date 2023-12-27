
def solution(plans):
    answer = []
    queue = []

    # 시작 시간 순으로 정렬
    plans = sorted(plans, key=lambda start: start[1])

    # 시간을 정수형으로 변경
    for plan in plans:
        start = list(map(int, plan[1].split(":")))
        plan[1] = start[0] * 60 + start[1]
        plan[2] = int(plan[2])

    for i in range(len(plans)):
        now = plans[i][1] + plans[i][2]

        if (i == len(plans)-1):
            # 만약 마지막 요소일 경우 완료하고 루프 종로
            answer.append(plans[i][0])
            break

        if (now > plans[i+1][1]):
            plans[i][2] = now - plans[i+1][1]  # 남은 시간 업데이트
            queue.append(plans[i])
        elif (now == plans[i+1][1]):
            answer.append(plans[i][0])
        else:
            answer.append(plans[i][0])
            while (len(queue) != 0):
                curr = queue.pop()
                if (now + curr[2] > plans[i+1][1]):
                    curr[2] = now + curr[2] - plans[i+1][1]
                    queue.append(curr)
                    break
                else:
                    answer.append(curr[0])
                    now += curr[2]

    # 남은 대기 큐 처리
    while (len(queue)):
        tmp = queue.pop()
        answer.append(tmp[0])

    return answer


plans = [["science", "12:40", "50"], ["music", "12:20", "40"],
         ["history", "14:00", "30"], ["computer", "12:30", "100"]]
solution(plans)
