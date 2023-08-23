#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

long long max(long long a, long long b){
    if(a>b){
        return a;
    }
    return b;
}

long long MaxTotalValue(int n, vector<int> a, vector<int> v, int x)
{

    long long  maxTotalValue = 0;

    for (int i = 0; i < n; ++i)
    {
        int sumAge = 0, sumValue = 0;
        for (int j = i; j < n; ++j)
        {
            sumAge += a[j];
            sumValue += v[j];
            int avgAge = sumAge / (j - i + 1);
            if (avgAge == x)
            {
                maxTotalValue = max(maxTotalValue, sumValue);
            }
        }
    }
    return maxTotalValue;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }

        int x;
        cin >> x;

        cout << MaxTotalValue(n, a, v, x) << endl;
    }

    return 0;
}
