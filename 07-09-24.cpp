#include <iostream>
#include <bits/stdc++.h>
#define mod 100000009
#define forloop(i, n) for (int i = 0; i < n; i++)
#define define_vec(n, vec) vector<int> vec(n);
#define input_vec(vec)  \
    for (auto &x : vec) \
        cin >> x;
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
    string str;
    cin >> str;

    int cntZero = 0, cntOne = 0, ans = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0')
        {
            cntZero++;
        }
        else
        {
            cntOne++;
        }
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '0' && cntZero != 0)
        {
            if (cntOne != 0)
            {
                cntOne--;
            }
        }
        else if (str[i] == '1' && cntOne != 0)
        {
            if (cntZero != 0)
            {
                cntZero--;
            }
        }
        else
        {
            ans++;
        }
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