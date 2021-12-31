/*
문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. (0 < A,B < 10^10000)

출력
첫째 줄에 A+B를 출력한다.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char arr[])
{
  int len = strlen(arr);
  for (int i = 0; i < len/2; i++) {
    char temp = arr[i];
    arr[i] = arr[len-i-1];
    arr[len-i-1] = temp;
  }
}

int main()
{
  char A[100002] = {0};
  char B[100002] = {0};
  char C[100003] = {0};

  scanf("%s %s",&A, &B);

  reverse(A);
  reverse(B);

  int carry = 0;
  int max;

  if (strlen(A) > strlen(B)) max = strlen(A);
  else max = strlen(B);

  for (int i = 0; i < max; i++) {
    int sum = A[i]-'0' + B[i] - '0' + carry;

    if (sum < 0) sum += '0';
    if (sum > 9) carry = 1;
    else carry = 0;

    C[i] = sum%10 + '0';
  }

  if (carry == 1) C[max] = '1';

  reverse(C);
  printf("%s", C);

}
