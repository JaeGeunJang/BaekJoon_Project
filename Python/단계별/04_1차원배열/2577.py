'''
문제
세 개의 자연수 A, B, C가 주어질 때 A x B x C를 계산한 결과에 
0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.

예를 들어 A = 150, B = 266, C = 427 이라면 A x B x C = 150 x 266 x 427 = 17037300 이 되고, 
계산한 결과 17037300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.

입력
첫째 줄에 A, 둘째 줄에 B, 셋째 줄에 C가 주어진다. A, B, C는 모두 100보다 크거나 같고, 
1,000보다 작은 자연수이다.

출력
첫째 줄에는 A x B x C의 결과에 0 이 몇 번 쓰였는지 출력한다. 
마찬가지로 둘째 줄부터 열 번째 줄까지 A x B x C의 결과에 
1부터 9까지의 숫자가 각각 몇 번 쓰였는지 차례로 한 줄에 하나씩 출력한다.
'''

temp = 1
for i in range (3) :
    temp *= int(input())

result = [0 for i in range (10)]

temp = str(temp)

for i in range (len(temp)) :
    result[int(temp[i])] += 1

for i in range (len(result)) :
    print(result[i])