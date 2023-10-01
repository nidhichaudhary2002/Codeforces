#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        long long time = b ;

        for (int i = 0; i < n; i++)
        {
           int ele;
           cin>>ele;
            time += min(ele, a-1);
        }
        cout << time << endl;
    }
    return 0;
}