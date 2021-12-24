/*
문제
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다.
당신은 그들에게 슬픈 진실을 알려줘야 한다.

입력
첫째 줄에는 테스트 케이스의 개수 C가 주어진다.

둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고,
이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

출력
각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int class;
  scanf("%d", &class);

  for (int i = 0; i < class; i++)
  {
    int stunum;
    int *score;
    float mean = 0, over = 0;

    scanf("%d", &stunum);

    score = malloc(sizeof(int)*stunum);

    for (int j = 0; j < stunum; j++) {
      scanf("%d", score+j);
      mean += *(score+j);
    }

    mean = mean / stunum;

    for (int j = 0; j < stunum; j++) {
      if (*(score+j) > mean) over += 1;
    }
    //printf("stunum = %d\n",stunum); test code
    //printf("Mean = %.2f\n", mean); test code
    printf("%.3f%%\n", over*100/stunum);
  }
}
