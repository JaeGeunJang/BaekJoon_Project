'''
문제
1보다 큰 자연수 중에서  1과 자기 자신을 제외한 약수가 없는 자연수를 소수라고 한다. 
예를 들어, 5는 1과 5를 제외한 약수가 없기 때문에 소수이다. 
하지만, 6은 6 = 2 x 3 이기 때문에 소수가 아니다.

골드바흐의 추측은 유명한 정수론의 미해결 문제로, 
2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다는 것이다. 이러한 수를 골드바흐 수라고 한다. 
또, 짝수를 두 소수의 합으로 나타내는 표현을 그 수의 골드바흐 파티션이라고 한다. 
예를 들면, 4 = 2 + 2, 6 = 3 + 3, 8 = 3 + 5, 10 = 5 + 5, 12 = 5 + 7, 14 = 3 + 11, 14 = 7 + 7이다. 
10000보다 작거나 같은 모든 짝수 n에 대한 골드바흐 파티션은 존재한다.

2보다 큰 짝수 n이 주어졌을 때, n의 골드바흐 파티션을 출력하는 프로그램을 작성하시오. 
만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
각 테스트 케이스는 한 줄로 이루어져 있고 짝수 n이 주어진다.

출력
각 테스트 케이스에 대해서 주어진 n의 골드바흐 파티션을 출력한다. 
출력하는 소수는 작은 것부터 먼저 출력하며, 공백으로 구분한다.

제한
4 ≤ n ≤ 10,000
'''

import sys

def prime (M) :
    prime = list()
    for i in range (2, M+1) :
        prime.append(i)
    
    for i in range (2, int((M+1)*0.5)+1) :
        length = len(prime)
        j = 0
        while (j < length) :
            if prime[j] != i and prime[j]%i == 0 :
                del prime[j]
                length -= 1
            else :
                j += 1
    
    return prime

def answer (M, arr) :
    arr = arr[1:]
    num = len(arr)//2

    for i in range (num, -1, -1) : 
        for j in range (i, len(arr)) :
            if arr[i]+arr[j] == M :
                print (arr[i], arr[j])
                return 0

def my_gold(A,B) :
    for i in range (A) :
        gold = int(B[i])

        arr = prime(gold)
        answer(gold, arr)


# https://yoonsang-it.tistory.com/31

def Goldbach(A, C):
    check = [False, False] + [True] * 10000
    
    for i in range(2, 101):
        if check[i] == True:
            for j in range(i + i, 10001, i):
                check[j] = False

    T = A
    for i in range(T):
        n = C[i]

        A = n // 2
        B = A
        for _ in range(10000):
            if check[A] and check[B]:
                print(A, B)
                break
            A -= 1
            B += 1


import time

A = 10
B = [10000-2*i for i in range(A)]
print(B)

start = time.time()
Goldbach(A,B)
end = time.time()
print(end - start)

start = time.time()
my_gold(A,B)
end = time.time()
print(end - start)