#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        vector<int> arr(4);

        for (int i = 0; i < 4; i++)
        {
            cin >> arr[i];
        }

        int max1 = INT_MIN;
        int max2 = INT_MIN;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > max1)
            {
                max2 = max1;
                max1 = arr[i];
            }
            else if (arr[i] > max2 && arr[i] < max1)
            {
                max2 = arr[i];
            }
        }

        if (((max(arr[0], arr[1]) == max1) && (max(arr[2], arr[3]) == max2)) || ((max(arr[0], arr[1]) == max2) && (max(arr[2], arr[3]) == max1)))
        {

            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
