# https://school.programmers.co.kr/learn/courses/30/lessons/135807

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def gcd_in_set(X, n):
    rtn = X[0]
    for i in range(1, n):
        p = min(rtn, X[i])
        q = max(rtn, X[i])
        rtn = gcd(p, q) if p != q else p
    return rtn

def solution(A, B):
    # A의 약수이며 B와는 서로소 or vice versa 인 양의 정수 a의 최댓값
    # A의 최대공약수 구하기
    n = len(A)
    m = len(B)
    gcd_a = gcd_in_set(A, n)
    gcd_b = gcd_in_set(B, m)
    print(gcd_a, gcd_b)
    
    # if gcd_a 와 gcd_b가 서로소라면 둘 중 큰 것을 리턴
    p, q = min(gcd_a, gcd_b), max(gcd_a, gcd_b)
    if(gcd_a != gcd_b and gcd(p, q) == 1):
        return q
    # else 
    


A = [14, 35, 119]	
B = [18, 30, 102]	
print(solution(A, B))