#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve()
{

    vector<int> arr;
    int k, n;
    cin >> n >> k;

    for (int i = k; i <= (k + n - 1); i++)
    {
        arr.push_back(i);
        // cout << i << ' ';
    }
    int sz = arr.size();
    vector<int> front(sz), back(sz);

    for (int i = 0; i < sz; i++)
    {
        if (i == 0)
        {
            front[i] = arr[i];
            continue;
        }
        front[i] = arr[i] + front[i - 1];
    }
    for (int i = sz - 1; i >= 0; i--)
    {
        if (i == sz - 1)
        {
            back[i] = arr[i];
            continue;
        }
        back[i] = arr[i] + back[i + 1];
    }

    int ans = INT_MAX;

    // printVector(front);
    // printVector(back);

    // cout << sz << " ";
    for (int i = 1; i < sz - 1; i++)
    {
        // cout << "Reached" << " ";
        // cout << abs(front[i] - back[i]) << " ";
        ans = min(ans, abs(front[i] - back[i]));
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}