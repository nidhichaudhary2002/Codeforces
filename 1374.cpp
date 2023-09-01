#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        int moves = 0;
        while (n != 1)
        {
            if (n % 6 == 0 && n >= 0)
            {
                n /= 6;
            }
            else if (n >= 0)
            {
                if (n > INT_MAX / 2)
                {
                    break;
                }
                n *= 2;
            }
            else
            {
                cout << -1 << endl;
                break;
            }
            moves++;
        }

        if (n == 1)
        {
            cout << moves << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}