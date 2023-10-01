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
        arr[0] = 1;
        arr[1] = 3;

        for (int i = 2; i < n; i++)
        {

            int x = arr[i - 1] + arr[i - 2];

            if (x % 3 == 0)
            {
                while (x % 3 == 0)
                {
                    x = x / 3;
                }
                while (x <= (arr[i - 1] + arr[i - 2]))
                {
                    x = x * 4;
                }
            }

            arr[i] = x;
        }

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}