/*
문제
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.

Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.

X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

입력
첫째 줄에 N이 주어진다.

둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

출력
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

제한
1 ≤ N ≤ 1,000,000
-10^9 ≤ Xi ≤ 10^9
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *pta, const void *ptb)
{
  int a = *(int *)pta;
  int b = *(int *)ptb;

  if (a < b) return -1;
  else if (a > b) return 1;
  else return 0;
}

int BSearch(int arr[], int len, int n)
{
  int low = 0;
  int high = len-1;


  while (1)
  {
    int mid = (low + high)/2;
    if (low > high) return -1;
    if (arr[mid] == n) return mid;
    else if (arr[mid] > n) high = mid - 1;
    else low = mid + 1;
  }
}

int main()
{
  int num;
  scanf("%d", &num);
  int nlist[num];
  int nindx[num];
  int idx = 0;

  for (int i = 0; i < num; i++) {
    int temp;
    scanf("%d", &nlist[i]);

    if (i == 0) {nindx[idx] = nlist[i]; idx += 1;}

    else {
      int flag = 0;
      for (int j = 0; j < idx; j++)
      {
        if (nindx[j] == nlist[i]) {flag = 1; break;}
      }
      if (flag == 0) {nindx[idx] = nlist[i]; idx += 1;}
    }
  }
  qsort(nindx, idx, sizeof(int), compare);
  for (int i = 0; i < num; i++) printf("%d ",BSearch(nindx, idx, nlist[i]));
  return 0;
}
