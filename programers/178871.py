# https://school.programmers.co.kr/learn/courses/30/lessons/178871
from typing import List


def solution(players: List[str], callings: List[str]):
    # calling 배열을 돌면서
    # 선수의 현재 등수를 갱신
    n, m = len(players), len(callings)
    dic, pos = {}, 0

    for i in range(n):
        # 등수를 이중 연결 리스트로 저장
        prev = players[i-1] if i > 0 else players[i]
        next = players[i+1] if i < n-1 else players[i]
        dic[players[i]] = [pos, prev, next]
        pos += 1

    for i in range(m):
        curr = callings[i]
        prev = dic[curr][1]
        next = dic[curr][2]

        # 리스트에서 삭제
        if dic[curr][0] == n-1:
            # 맨 뒤를 삭제하는 경우
            dic[prev][2] = prev
        else:
            # 그렇지 않은 경우
            dic[prev][2] = next
            dic[next][1] = prev

        # prev 앞에 삽입
        if dic[prev][0] == 0:
            # 맨 앞에 삽입하는 경우
            dic[curr][1] = curr
        else:
            # 그렇지 않은 경우
            dic[curr][1] = dic[prev][1]
            dic[dic[prev][1]][2] = curr

        dic[curr][2] = prev
        dic[prev][1] = curr

        # 순위 변경
        dic[curr][0] -= 1
        dic[prev][0] += 1

    # 최종 순위 배열
    players.sort(key=lambda p: dic[p][0])
    return players


solution(["mumu", "soe", "poe", "kai", "mine"], ["kai", "kai", "mine", "mine"])
