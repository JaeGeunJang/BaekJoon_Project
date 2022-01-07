'''
문제
2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, 
x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 
좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
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
        if low_arr[l][0] < high_arr[h][0] :
            merged_arr.append(low_arr[l])
            l += 1
        elif low_arr[l][0] == high_arr[h][0] :
            if low_arr[l][1] < high_arr[h][1] :
                merged_arr.append(low_arr[l])
                l += 1
            else :
                merged_arr.append(high_arr[h])
                h += 1
        else : 
            merged_arr.append(high_arr[h])
            h += 1
    
    merged_arr += low_arr[l:]
    merged_arr += high_arr[h:]

    return merged_arr

nlist = list()

num = int(sys.stdin.readline())
for i in range (num) :
    nlist.append(list(map(int, sys.stdin.readline().split())))

result = merge_sort(nlist)

for i in result :
    print(i[0], i[1])