'''
문제
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

입력
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

출력
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.
'''


def merge_sort(arr) :
    if len(arr) < 2 :
        return arr
    
    mid = len(arr)//2
    low_arr = merge_sort(arr[:mid])
    high_arr = merge_sort(arr[mid:])

    merged_arr = []

    l = h = 0

    while l < len(low_arr) and h < len(high_arr) :
        if low_arr[l] < high_arr[h] :
            merged_arr.append(low_arr[l])
            l += 1
        else : 
            merged_arr.append(high_arr[h])
            h += 1
    
    merged_arr += low_arr[l:]
    merged_arr += high_arr[h:]

    return merged_arr

import sys
num = int(input())

nlist = list(map(int, sys.stdin.readline().split()))

idxn = merge_sort(list(set(nlist)))
#내장 함수 사용 시 3배이상 빨라짐 - Why?

dic = {idxn[i] : i for i in range (len(idxn))}
print(dic)

for i in nlist :
    print(dic[i])