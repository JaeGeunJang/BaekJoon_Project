'''
문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

1. 길이가 짧은 것부터
2. 길이가 같으면 사전 순으로

입력
첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 
둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 
주어지는 문자열의 길이는 50을 넘지 않는다.

출력
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
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
        if low_arr[l] == high_arr[h] :
            merged_arr.append(low_arr[l])
            l += 1
            h += 1

        elif low_arr[l][0] < high_arr[h][0] :
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

num = int(input())


nlist = list()

for i in range (num) : 
    words = sys.stdin.readline().rstrip()
    nlist.append([len(words),words])

nlist = merge_sort(nlist)

for i in nlist :
    print(i[1])