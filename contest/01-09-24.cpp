#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isAlternate(string s, int n)
{

    if (n % 2 == 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                return false;
            }
        }
    }
    char prev = s[0];
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && s[i] != prev)
        {
            return false;
        }
    }
    return true;
}

int func(int idx, int n, string s,bool isDeleted)
{
    if(isAlternate(s,n)){
        return 0;
    }
    int cnt1;
    if(!isDeleted){
        string curString="";
        for(int i=0;i<idx-1;i++){
            curString+=s[i];
        }
        for(int i=idx+1;i<n;i++){
            curString+=s[i];
        }
        cnt1=1+func(idx-1,n,curString,true);
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
        int n, s;
        cin >> n >> s;
    }
}