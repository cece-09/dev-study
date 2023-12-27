# https://school.programmers.co.kr/learn/courses/30/lessons/250121
from typing import List


def solution(data: List[List[int]], ext: str, val_ext: int, sort_by: str):
    fields = {
        "code": 0,
        "date": 1,
        "maximum": 2,
        "remain": 3,
    }

    # data에서 ext값이 val_ext보다 작은 경우 뽑기
    new_data = []
    for d in data:
        if d[fields[ext]] < val_ext:
            new_data.append(d)

    # sort_by에 해당하도록 정렬
    new_data.sort(key=lambda x: x[fields[sort_by]])

    return new_data


print(solution([[1, 20300104, 100, 80], [2, 20300804, 847, 37], [
    3, 20300401, 10, 8]], "date", 20300501, "remain"))
