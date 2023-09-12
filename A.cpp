#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void findTwoBases(int &a, int &b, int p)
{

    unordered_map<int, int> mp;

    for (int i = 1; i <= p; i++)
    {
        mp[i % p] = i;
    }

    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }

    for (int i = 1; i < p; i++)
    {
        if (mp.find(p % i) != mp.end())
        {
            a = i;
            b = mp[p % i];
            break;
        }
    }
}

int main()
{
    // int t;
    // cin >> t;

    // while (t--)
    // {
    int p, a = -1, b = -1;
    cin >> p;

    findTwoBases(a, b, p);

    if (a == -1 && b == -1)
    {
        cout << -1;
    }
    else
    {
        cout << max(a, b) << " " << min(a, b);
    }
    // }
    return 0;
}