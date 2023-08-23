#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int a = 0; a <= pow(n, 0.5); a++)
    {
        for (int b = 0; b <= pow(m, 0.5); b++)
        {
            if ((pow(a, 2) + b == n) && (pow(b, 2) + a == m))
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}