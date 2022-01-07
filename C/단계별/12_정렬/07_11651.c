#include <stdio.h>
#include <stdlib.h>

struct axis {
  int x;
  int y;
};

int compare(struct axis *a, struct axis *b)
{
  if (a->y > b->y) return 1;
  if (a->y == b->y && a->x > b->x) return 1;
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
