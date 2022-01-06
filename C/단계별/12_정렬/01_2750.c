/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int a[], int len)
{
  for (int i = len-1; i > 0; i--) {
    for (int j = 0; j < i; j++)
    {
      if (a[j] > a[j+1]) swap(&a[j], &a[j+1]);
    }
  }
}

int main()
{
  int num;
  scanf("%d",&num);

  int nlist[num];

  for (int i = 0; i < num; i++) scanf("%d", &nlist[i]);

  bubbleSort(nlist, num);

  for (int i = 0; i < num; i++) printf("%d\n",nlist[i]);

  return 0;
}
