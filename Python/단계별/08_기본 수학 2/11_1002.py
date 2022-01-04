'''
문제
A과 B은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 
다음은 A과 B의 사진이다.

이석원은 A과 B에게 상대편 마린(C)의 위치를 계산하라는 명령을 내렸다. 
A과 B은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.

A의 좌표 (x1, y1)와 B의 좌표 (x2, y2)가 주어지고, 
A이 계산한 C과의 거리 r1과 B이 계산한 C과의 거리 r2가 주어졌을 때, 
C이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 이루어져 있다.

한 줄에 x1, y1, r1, x2, y2, r2가 주어진다. x1, y1, x2, y2는 -10,000보다 크거나 같고, 
10,000보다 작거나 같은 정수이고, r1, r2는 10,000보다 작거나 같은 자연수이다.

출력
각 테스트 케이스마다 C이 있을 수 있는 위치의 수를 출력한다. 
만약 C이 있을 수 있는 위치의 개수가 무한대일 경우에는 -1을 출력한다.
'''
import math

cases = int(input())

A = list()
B = list()

for i in range (cases) :
    axis = list(map(int, input().split()))

    A.append(list(axis[:3]))
    B.append(list(axis[3:]))


for i in range (cases) :
    dist = math.sqrt((A[i][0] - B[i][0])**2 + (A[i][1] - B[i][1])**2)
    
    r1 = A[i][2]
    r2 = B[i][2]
    
    if dist == 0 and r1 == r2 :
        print(-1)
    
    elif abs(r1-r2) == dist or r1 + r2 == dist :
        print(1)
    
    elif abs(r1-r2) < dist and dist < r1 + r2 :
        print(2)
    
    else :
        print(0)