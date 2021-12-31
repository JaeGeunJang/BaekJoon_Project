/*
문제
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

출력
N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다. N이 1인 경우 아무것도 출력하지 않는다.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void bubble(int arr[], int count)
{
  int temp;

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - 1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int prime(int n)
{
  int flag = 1;
  if (n == 1) return 0;
  else if (n == 2 || n == 3) return 1;
  else
  {
    for (int i = 2; i < n; i++) {
      if(n % i == 0) {flag = 0; break;}
    }
  }
  return flag;
}

int main()
{
  int N;
  int sqrtnum[3200];

  scanf("%d",&N);

  int sqrtN = (int)sqrt(N);
  //printf("%d", sqrtN);

  if (N == 1) return 0;
  else if (N <= 3) {printf("%d", N); return 0;}
  else if (prime(N)) {printf("%d", N); return 0;}
  int idx = 0;

  for (int i = 2; i <= sqrtN; i++) {
    if (N % i == 0) {
      if (N == i*i) {sqrtnum[idx] = i; idx += 1;}
      else {
        sqrtnum[idx] = i;
        sqrtnum[idx+1] = N/i;
        idx += 2;
      }
    }
  }

  bubble(sqrtnum,idx);

  int k = 0;

  while(N != 1)
  {
    while(N % sqrtnum[k] == 0) {
      printf("%d\n", sqrtnum[k]);
      N = N / sqrtnum[k];
    }
    k += 1;
  }
}
