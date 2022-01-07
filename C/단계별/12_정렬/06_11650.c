/*
문제
2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로,
x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다.
둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고,
위치가 같은 두 점은 없다.

출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>

struct axis {
  int x;
  int y;
};

int compare(struct axis *a, struct axis *b)
{
  if (a->x > b->x) return 1;
  if (a->x == b->x && a->y > b->y) return 1;
  else return -1;
}

int main()
{
  int num;
  int x,y;

  scanf("%d", &num);
  struct axis nlist[num];

  for (int i = 0; i < num; i++) {
    scanf("%d %d", &x, &y);
    nlist[i].x = x;
    nlist[i].y = y;
  }
  qsort(nlist, num, sizeof(nlist[0]), compare);
  for (int i = 0; i < num; i++) printf("%d %d\n", nlist[i].x, nlist[i].y);

}
