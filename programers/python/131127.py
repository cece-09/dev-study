# https://school.programmers.co.kr/learn/courses/30/lessons/131127

# 구매 또는 구매 취소
def buy(key, hash, reverse = False):
    if key in hash:
        hash[key] += 1 if reverse else -1
        return True
    else:
        return False
    
# 모두 구매 가능한지 체크
def check(hash):
    keys = hash.keys()
    for key in keys:
        if hash[key] > 0:
            return 0
    return 1


# 원하는 모든 제품과 수량이 할인하는 날짜와
# 10일 연속으로 일치하는 날짜의 수
def solution(want, number, discount):
    answer = 0
    hash = {}

    n = len(want)
    m = len(discount)
    for i in range(n):
        hash[want[i]] = number[i]

    # 첫째 날 가입한 경우
    for i in range(0, 10):
        buy(discount[i], hash)
    answer += check(hash)
    
    # i = 10, n 까지 discount를 돌면서 sliding window
    # hash값을 재조정하고 <= 여부를 확인
    for i in range(1, m-9): # 최소 10일까지 검색
        j = i + 9
        buy(discount[i-1], hash, reverse=True)
        buy(discount[j], hash)
        answer += check(hash)
    
    return answer


want = ["banana", "apple", "rice", "pork", "pot"]
number = [3, 2, 2, 2, 1]
discount = ["apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana", "chicken", "apple"]

print(solution(want, number, discount))