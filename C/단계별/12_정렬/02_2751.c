#include <stdio.h>
#include <stdlib.h>

int compare(int *a, int *b)
{
  if (*a > *b) return 1;
  else if (*a < *b) return -1;
  else return 0;
}

int main()
{
  int num;
  scanf("%d", &num);

  int nlist[num];

  for (int i = 0; i < num; i++) scanf("%d", &nlist[i]);

  qsort(nlist, num, sizeof(nlist[0]), compare);

  for (int i = 0; i < num; i++) printf("%d\n", nlist[i]);

  return 0;
}
