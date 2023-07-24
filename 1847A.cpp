#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(int *arr, int n, int k)
{
    if (k > n)
    {
        return -1;
    }
    int ans = 0;
    priority_queue<int> pq;

    pq.push(0);
    // arr[n-1]=0;
    for (int i = n - 2; i >= 0; i--)
    {
        pq.push(abs(arr[i + 1] - arr[i]));
    }

    while (k--)
    {
        pq.pop();
    }

    while (!pq.empty())
    {
        ans += pq.top();

        pq.pop();
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << func(arr, n, k - 1) << endl;
    }

    return 0;
}