#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, c;
        cin >> n >> m >> c;

        float avg = (n + m) / 2;

        float attempts = (max(n, m) - avg) / c;

        cout << ceil(attempts) << endl;
    }
    return 0;
}