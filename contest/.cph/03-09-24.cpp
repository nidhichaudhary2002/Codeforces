#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int x, y;
double maxPow;
void printVector(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double dist(int x1, int x2, int y1, int y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void func(int currx, int curry, int step, int &ans, int currans, bool rightmove)
{

    if (dist(currx, x, curry, y) > maxPow || currx > x || curry > y)
    {
        // cout << maxPow;
        return;
    }

    if (currx == x && curry == y)
    {
        ans = min(ans, currans);
        return;
    }
    if (rightmove)
    {
        for (int i = 1; i <= step; i++)
        {
            func(currx + i, curry, step, ans, currans + 1, false);
        }
    }
    else
    {
        for (int i = 1; i <= step; i++)
        {
            func(currx, curry + i, step, ans, currans + 1, true);
        }
    }
}

void solve()
{
    int step;
    cin >> x >> y >> step;
    int ans = INT_MAX;
    maxPow = dist(0, x, 0, y);
    func(0, 0, step, ans, 0, true);
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