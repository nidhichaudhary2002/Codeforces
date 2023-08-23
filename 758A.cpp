#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max - arr[i];
    }

    cout << ans << endl;

    return 0;
}