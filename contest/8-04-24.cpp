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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int cnt = 0;
        int l = 0, r = n - 1;
        bool first = true;
        while (l <= r && k--)
        {
            if (arr[r] == 0)
            {
                r--;
            }
            if (arr[l] == 0)
            {
                l++;
            }

            if (first)
            {
                arr[l]--;
                first = false;
            }
            else
            {
                arr[r]--;
                first = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                // cout<<i<<" ";
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}