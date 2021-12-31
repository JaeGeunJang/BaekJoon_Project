'''
문제
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

출력
N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다. N이 1인 경우 아무것도 출력하지 않는다.
'''

def prime (n) :
    flag = True

    if n == 1 :
        return False
    elif n == 2 or n == 3 :
        return True
    else :
        for i in range (2, int((n**1/2)+1)) :
            if n % i == 0 :
                flag = False
                break
    
    return flag

N = int(input())
sqrtN = int(N ** 1/2)
listN = list()

if (N == 1) :
    exit()

elif (N <= 3) :
    print(N)
    exit()

elif (prime(N)) :
    print(N)
    exit()

else :
    for i in range (2, sqrtN+1) :
        if (N % i == 0) :
            if (N == i*i) :
                listN.append(i)
            else :
                listN.append(i)
                listN.append(int(N/i))
    
    listN.sort()

    idx = 0

    while N != 1 :
        while N%listN[idx] == 0 :
            print(listN[idx])
            N = N/listN[idx]
        idx += 1
