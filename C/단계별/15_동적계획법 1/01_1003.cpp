#include <iostream>
using namespace std;

int zeros = 0;
int ones = 0;

int fibonacci(int n) {
    if (n == 0) {
        zeros += 1;
        return 0;
    }
    else if (n == 1) {
        ones += 1;
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main()
{
    int dyn[41][2];
    for (int i = 0; i <= 41; i++)
    {
        if (i == 0) 
        {
            dyn[i][0] = 1;
            dyn[i][1] = 0;
        }
        else if (i == 1)
        {
            dyn[i][0] = 0;
            dyn[i][1] = 1;
        }
        else
        {
            dyn[i][0] = dyn[i - 1][0] + dyn[i - 2][0];
            dyn[i][1] = dyn[i - 1][1] + dyn[i - 2][1];
        }
    }

    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int n;
        cin >> n;
        cout << dyn[n][0] << " " << dyn[n][1] << endl;
    }
}