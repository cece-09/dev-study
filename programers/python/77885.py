# https://school.programmers.co.kr/learn/courses/30/lessons/77885


# x보다 크고 x와 비트가 1-2개 다른 수 중
# 최솟값을 배열에 담아 리턴합니다.
def solution(numbers):        
    def get_ans(num):
        tmp = 1
        if num == tmp: return num+1 # 1이면 2입니다
        while tmp < num:
            if not (num & tmp):
                break
            tmp *= 2
        num |= tmp             # 0인 비트를 1로 변경
        num &= ~(tmp >> 1)     # 그 하위 비트를 0으로 변경
        return num
        
    answer = []
    n = len(numbers)
    for i in range(n):
        output = get_ans(numbers[i])
        answer.append(output)
        
    return answer


numbers = [1001,337,0,1,333,673,343,221,898,997,121,1015,665,779,891,421,222,256,512,128,100]
expects = [1002, 338, 1, 2, 334, 674, 347, 222, 899, 998, 122, 1019, 666, 781, 893, 422, 223, 257, 513, 129, 101]
print(solution(numbers))