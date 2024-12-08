#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define mxx 1e18 - 1
using namespace std;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

void solve()
{
    ll n;
    cin >> n;

    vector<ll> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll l = -1e15;
    ll r = 1e15;

    ll minimizeMaximum = 0;
    ll maximizeMinimum = 0;

    while (l <= r)
    {
        ll mid = (l + r) / 2ll;
        vector<ll> helper = v;
        for (ll i = 0; i < n - 1; i++)
        {
            if (helper[i] > mid)
            {
                ll extra = helper[i] - mid;
                helper[i + 1]+= extra;
                helper[i]=mid;
            }
        }
        if (helper[n - 1] <= mid)
        {
            minimizeMaximum = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    l=-1e15;
    r=1e15;

    while (l <= r)
    {
        ll mid = (l + r) / 2ll;
        vector<ll> helper = v;

        for(ll i=n-1;i>0;i--)
        {
            if(helper[i]<mid)
            {
                ll extra=mid-helper[i];
                helper[i-1]-=extra;
                helper[i]=mid;
            }
        }

        if (helper[0] >= mid)
        {
            maximizeMinimum = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout<<max(0ll,minimizeMaximum-maximizeMinimum)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}