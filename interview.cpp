#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        set<char> st;
        string ans = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (st.find(s[i]) != st.end())
            {
                ans += s[i];
                st.insert(s[i]);
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}