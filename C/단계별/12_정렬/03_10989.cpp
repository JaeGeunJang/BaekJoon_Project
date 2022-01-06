#include <iostream>

using namespace std;

int main()
{
  int num;
  int nlist[10000] = {0,};
  int n;

  cin >> num;

  for (int i = 0; i < num; i++) {
    scanf("%d",&n); //cin 보다 scanf의 입력속도가 더 빠름
    nlist[n-1] += 1;
  }

  for (int i = 0; i < 10000; i++) {
    if (nlist[i] != 0) {
      for (int j = 0; j < nlist[i]; j++) printf("%d\n", i+1); //scanf와 동일한 이유
    }
  }

  return 0;
}
