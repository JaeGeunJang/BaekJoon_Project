#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int num;
  int nlist[8001] = {0,};
  int nsize = sizeof(nlist)/sizeof(int);

  double mean = 0;
  int max = -4001;
  int min = 4001;

  int n; //input number
  int f = 0, find = 0; //find median value
  int mval = 0, midx = 0; //find mode
  int modes[125];


  scanf("%d", &num);
  int mid = (num+1)/2;

  for (int i = 0; i < num; i++) {
    scanf("%d", &n);
    nlist[n+4000] += 1;
    mean += (double)n/(double)num;

    if (max < n) max = n;
    if (min > n) min = n;
  }

  for (int i = 0; i < 8001; i++) {
    if (nlist[i] != 0) {
      if (find < mid) {
        find += nlist[i]; //finded numbers
        f = i-4000; //median value
      }
    }

    if (nlist[i] > mval) {
      mval = nlist[i];
      modes[0] = i-4000;
      midx = 1;
    }
    else if (nlist[i] == mval) {
      modes[midx] = i-4000;
      midx += 1;
    }
  }

  printf("%.0lf\n", round(mean));
  printf("%d\n", f);

  if (midx == 1) printf("%d\n", modes[0]);
  else printf("%d\n", modes[1]);

  printf("%d", max - min);
}
