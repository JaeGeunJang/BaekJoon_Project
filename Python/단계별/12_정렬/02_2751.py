'''
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 
이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
'''
import sys

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

nums = int(input())
nlist = list()

for i in range (nums) :
    nlist.append(int(sys.stdin.readline()))

nlist = merge_sort(nlist)

for i in nlist :
    print(i)