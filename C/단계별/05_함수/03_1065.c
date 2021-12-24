/*
문제
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다.
N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은
한수의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.
*/

#include <stdio.h>

int hans(int num)
{
  int hans = 0;
  int huns, tens, rest;

  for (int i = 1; i <= num; i++) {

    if (i == 1000) break;
    else if (i < 100) hans += 1;
    else {
      huns = i/100;
      tens = (i/10)%10;
      rest = i%10;
      if (huns - tens == tens - rest) hans += 1;
    }
  }

  return hans;
}

int main()
{
  int num;
  scanf("%d",&num);
  printf("%d",hans(num));
}
