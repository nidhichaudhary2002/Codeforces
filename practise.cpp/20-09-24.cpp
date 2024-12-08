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
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int num1 = 0;
    int num2 = 0;
    int minimaIdx = -1;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            minimaIdx = i;
            break;
        }
    }
    cout << "minimaIdx " << minimaIdx << endl;

    for (int i = 0; i < n; i++)
    {
        if (i <= minimaIdx)
        {
            num1 += arr[i];
        }
        else
        {
            num2 += arr[i];
        }
    }
    cout << num1 << " " << num2 << endl;
    cout << abs(num1 - num2) << endl;
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