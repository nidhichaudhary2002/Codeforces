#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        long long k;

        cin >> n >> m >> k;

        int *arr = new int[n];
        int *arr2 = new int[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        sort(arr, arr + n);
        sort(arr2, arr2 + m);

        if (k >= 1)
        {
            if (arr[0] < arr2[m - 1])
            {
                swap(arr[0], arr2[m - 1]);
            }

            sort(arr, arr + n);
            sort(arr2, arr2 + m);
            k--;
        }
        long long ans = 0;
        if (k % 2 == 1)
        {
            swap(arr2[0], arr[n - 1]);
            sort(arr, arr + n);
            sort(arr2, arr2 + m);
        }

        for (int i = 0; i < n; i++)
        {
            ans += arr[i];
        }

        cout << ans << endl;
    }
    return 0;
}