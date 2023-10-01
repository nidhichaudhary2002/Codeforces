#include <bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i)
#define R(i, j, k) for (int i = (j); i >= (k); --i)
#define ll long long
#define me(a, x) memset(a, x, sizeof(a))
using namespace std;
#define ull unsigned long long
const int N = 1e6 + 7;
int a[N], b[N];
int n, m;
#define ll long long
#define sz(a) ((int)(a).size())
#define vi vector<int>

void Main()
{
    cin >> m >> n;
    L(i, 1, m)
    {
        cin >> b[i];
    }
    L(i, 1, n)
    {
        cin >> a[i];
    }
    int op = 0;
    L(i, 1, m)
    {
        op ^= b[i];
    }

    int min = 0, max = 0;

    if (m & 1)// if m is odd
    {
        min = op;
        L(i, 1, n)
        {
            op |= a[i];
        }
        max = op;
    }
    else
    {
        max = op;
        L(i, 1, n)
        {
            op &= ~a[i];
        }
        min = op;
    }
    cout << min << ' ' << max << '\n';
}
int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        Main();
    return 0;
}
