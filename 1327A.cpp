#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;

        if ((int)sqrt(n) == k)
        {
            cout << "Yes"<<endl;
        }
        else
        {
            cout << "No"<<endl;
        }
    }

    return 0;
}