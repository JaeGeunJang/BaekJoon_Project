'''
문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. (0 < A,B < 10^10000)

출력
첫째 줄에 A+B를 출력한다.
'''

nums = str(input())
nums = nums[::-1]
nums = nums.split()

A = list(map(int,str(nums[0])))
B = list(map(int,str(nums[1])))

A.append(0)
B.append(0)

carry = 0
if len(B) > len(A) :
    maxim = len(B)
    for i in range (len(B) - len(A)) :
        A.append(0)
else :
    maxim = len(A)
    for i in range (len(A) - len(B)) :
        B.append(0)
ans = ''

for i in range (maxim) :
    temp = A[i] + B[i] + carry
    if temp >= 10 :
        carry = 1
    else :
        carry = 0
        
    ans += str(temp%10)
    
ans = ans[::-1]

if ans[0] == '0' :
    print(ans[1:])
else :
    print(ans)
