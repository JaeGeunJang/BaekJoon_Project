/*
문제
알파벳 대소문자로 된 단어가 주어지면,
이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오.
단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다.
주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다.
단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
*/

#include <stdio.h>

int main()
{
  char word[1000001];
  int alphas[26] = {0,};
  int result[2] = {0,};
  int ans, i = 0;

  scanf("%s",word);

  while (word[i] != '\0') {
    int ans = (int)word[i];
    if (ans >= 97) alphas[ans-97] += 1;
    else alphas[ans-65] += 1;

    i += 1;
  }

  i = 0;


  for (int j = 0; j < 26; j++) {
    if (alphas[j] > result[1]) {
      result[0] = j;
      result[1] = alphas[j];
    }
    else if (alphas[j] == result[1]) result[0] = -1;
  }

  if (result[0] != -1) printf("%c", result[0]+65);
  else printf("?");


}
