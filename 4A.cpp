#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a;
    cin >> a;
 
    if (a % 2 == 0 && a > 2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}