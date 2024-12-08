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

    char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

    int number_of_var_to_be_doubled = (n / 5)+(n%5);
    int multiple_of_var = n / 5;

    string ans = "";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < multiple_of_var; j++)
        {
            ans += vowel[i];
        }
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