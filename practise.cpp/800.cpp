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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    set<int> seta;
    set<int> setb;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        seta.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        setb.insert(b[i]);
    }
    int i = 0, j = 0, k = n - 1, l = n - 1;
    while (i <= k || j <= l)
    {
        if (i < k)
        {
            if (setb.find(a[i]) != setb.end())
            {
                seta.erase(a[i]);
                i++;
            }
            else
            {
                seta.erase(a[k]);
                k--;
            }
        }

        if (j < l)
        {

            if (seta.find(b[j]) == seta.end())
            {
                setb.erase(b[j]);
                j++;
            }
            else
            {
                setb.erase(b[l]);
                l--;
            }
        }
    }

    if (a[i] == b[j])
    {
        cout << "Bob" << endl;
    }
    else
    {
        cout << "alice" << endl;
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