#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }

        int findNum = INT_MIN;
        for (auto it : mp)
        {
            if (it.second == 1)
            {
                findNum = it.first;
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (findNum == arr[i])
            {
                cout << i +1<< endl;
                break;
            }
        }
    }
    return 0;
}