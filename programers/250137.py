# https://school.programmers.co.kr/learn/courses/30/lessons/250137?language=python3

def solution(bandage, health, attacks):
    exe_time = bandage[0]
    rec_per_sec = bandage[1]
    rec_per_exe = bandage[2]

    curr_hp = health
    n = len(attacks)

    for i in range(n):
        attk_time = attacks[i][0]
        attk_harm = attacks[i][1]

        prev_time = 0 if i == 0 else attacks[i-1][0]
        gap_time = attk_time - prev_time - 1

        # 공격 이전 나의 체력
        updated = curr_hp + gap_time * rec_per_sec

        # 만약 연속 성공이라면 추가 체력 획득
        if gap_time >= exe_time:
            updated += rec_per_exe * (gap_time // exe_time)

        curr_hp = min(updated, health)

        # 공격 이후 나의 체력
        curr_hp -= attk_harm
        if curr_hp <= 0:  # 만약 죽었으면 즉시 리턴
            return -1

    return curr_hp


# ====== Test Case ====== #
tc = [
    {
        'band': [5, 1, 5],
        'heal': 30,
        'attk': [[2, 10], [9, 15], [10, 5], [11, 5]]
    },
    {
        'band': [3, 2, 7],
        'heal': 20,
        'attk': [[1, 15], [5, 16], [8, 6]],
    },
    {
        'band': [4, 2, 7],
        'heal': 20,
        'attk': [[1, 15], [5, 16], [8, 6]],
    },
    {
        'band': [1, 1, 1],
        'heal': 5,
        'attk': [[1, 2], [3, 2]],
    },
    {
        'band': [10, 10, 100],
        'heal': 10,
        'attk': [[1, 15], [3, 1]],
    }
]


def do_test(num: int):
    print(solution(tc[num-1]['band'], tc[num-1]['heal'], tc[num-1]['attk']))


do_test(5)
