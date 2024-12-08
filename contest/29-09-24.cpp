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

int helper(long long n, long long k)
{
    int op = 0;
    int x = floor((log(n) / log(k)));

    while (n > 0)
    {
        double pwer = pow(k, x);
        if (pwer <= n)
        {
            n -= pwer;
        }
        if (pwer > n)
        {
            x--;
        }
        cout << n << " " << x << endl;
        op++;
    }

    return op;
}

void solve()
{
    long long n, k;
    cin >> n >> k;
    if (k == 1)
    {
        cout << n << '\n';
    }
    else
    {
        cout << helper(n, k) << '\n';
    }
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
