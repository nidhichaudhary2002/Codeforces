#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            result ^= arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == result)
            {
                cout << i;  
            }
        }
    }
    return 0;
}