/*
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000)
M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void prime(int M, int N)
{
  int numN = N+ 1;

  int *prime = malloc(sizeof(int)*numN);

  for (int i = 0; i < numN; i++) *(prime+i) = 1;

  int sqnum = sqrt(numN) + 1;

  for (int i = 2; i < sqnum; i++) {
    if (prime[i] == 1) {
      for (int j = 2*i; j < numN; j += i) *(prime+j) = 0;
    }
  }

  for (int i = M; i < numN; i++) {
    if (i > 1 && *(prime+i) == 1) printf("%d\n",i);
  }
}

int main()
{
  int M, N;
  scanf("%d %d", &M, &N);

  prime(M,N);

  return 0;
}
