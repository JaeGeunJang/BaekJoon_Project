'''
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) 
M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
'''

def prime (M, N) :
    N += 1
    prime = [True] * N
    for i in range (2, int(N*0.5)+1) :
        if prime[i] :
            for j in range (2*i, N, i) : 
                prime[j] = False
    
    for i in range (M, N) :
        if i > 1 and prime[i] == True :
            print(i)

M, N = map(int, input().split())

prime(M,N)