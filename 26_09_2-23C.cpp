#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        unsigned long long x;
        cin >> n >> k >> x;

        if (k > n)
        {
            cout << "No1" << endl;
        }
        else
        {
            long long sumN = n * (n + 1) / 2;
            long long sumK = k * (k + 1) / 2;

            // cout << sumN << " " << x << " " << sumK << endl;
            if (sumK <= x && sumN >= x)
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}