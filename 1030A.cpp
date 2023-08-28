#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    bool isHard = false;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            cout << "HARD";
            isHard = true;
            break;
        }
    }
    if (!isHard)
    {
        cout << "Easy";
    }

    cout << endl;

    return 0;
}