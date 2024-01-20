# https://school.programmers.co.kr/learn/courses/30/lessons/118667

def solution(q1, q2):
    count = 0
    s1 = sum(q1)
    s2 = sum(q2)
    # 합이 짝수가 아닌 경우 -1
    if (s1 + s2) % 2:
        return -1
    
    # 큐의 합이 같아지는 경우
    tar = (s1 + s2) // 2
    # 최대 반복 횟수, q1과 q2가 2번 swap된 경우
    max_repeat = c1 * 4 

    # 맨 앞부터 원소 비교
    f1 = f2 = 0
    c1 = c2 = len(q1)
    while (f1 < c1 and f2 < c2):
        if count == max_repeat:
            return -1
        if s1 < tar:
            q1.append(q2[f2])
            s1 += q2[f2] ; c1 += 1 # push
            s2 -= q2[f2] ;         # pop
            f2 += 1
            count += 1
        elif s2 < tar:
            q2.append(q1[f1])
            s2 += q1[f1] ; c2 += 1 # push
            s1 -= q1[f1] ;         # pop
            f1 += 1
            count += 1
        if s1 == tar and s2 == tar:
            return count

    return -1


queue1 = [3, 2, 7, 2]
queue2 = [4, 6, 5, 1]
print(solution(queue1, queue2))