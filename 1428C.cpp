#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        stack<char> st;

        for (int i = 0; i < str.length(); i++)
        {

            st.push(str[i]);

            if (st.top() == 'B')
            {
                if (st.size() >= 2)
                {
                    st.pop();
                    st.pop();
                }
            }
        }

        cout << st.size() << endl;
    }

    return 0;
}
// AABBBABBBB