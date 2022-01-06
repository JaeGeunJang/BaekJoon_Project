#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int a[], int len)
{
  for (int i = len-1; i > 0; i--) {
    for (int j = 0; j < i; j++)
    {
      if (a[j] > a[j+1]) swap(&a[j], &a[j+1]);
    }
  }
}

int main()
{
  int num;
  cin >> num;
  int nlist[num];

  for (int i = 0; i < num; i++) cin >> nlist[i];

  bubbleSort(nlist, num);

  for (int i = 0; i < num; i++) cout << nlist[i] << endl;

}
