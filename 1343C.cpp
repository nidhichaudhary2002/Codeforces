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

        int sign;
        if (arr[0] > 0)
        {
            sign = 1;
        }
        else
        {
            sign = -1;
        }

        long long maxE = INT_MIN, ans = 0;

        for (int i = 0; i < n; i++)
        {
            int curr_sign;
            if (arr[i] > 0)
            {
                curr_sign = 1;
            }
            else
            {
                curr_sign = -1;
            }

            if (curr_sign == sign)
            {
                maxE = max((long long)arr[i], maxE);
            }
            else
            {
                ans += maxE;
                sign = curr_sign;
                maxE = arr[i];
            }
        }
        ans += maxE;
        cout << ans << endl;
    }

    return 0;
}