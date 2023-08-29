#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        bool possible = true;
        int n = s.length();
        int idx=-1;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '1' && s[i + 1] == '1' )
            {
                idx=i;
                break;
            }
        }
        if(idx==-1){
            cout<<"YES\n";
            continue;
        }

        for (int i = idx+1; i < n - 1; i++)
        {
            if (s[i] == '0' && s[i + 1] == '0' )
            {
                possible=false;
                break;
            }
        }
        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
