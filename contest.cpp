#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    if (n <= 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    int i = 5;
    while (i * i <= n)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
        i += 6;
    }
    return true;
}

int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = min(a, b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}

int main()
{
    int t;
    cin >> t;

    vector<bool> prime_bools(10000001, true);
    prime_bools[0] = prime_bools[1] = false;

    for (int i = 2; i <= sqrt(10000001); ++i)
    {
        if (prime_bools[i])
        {
            for (int j = i * i; j <= 10000001; j += i)
            {
                prime_bools[j] = false;
            }
        }
    }

    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int i = 2, n = max(l, r);
        pair<int, int> ans;
        ans = {-1, -1};

        for (int i = l; i >= 1; i--)
        {

            if (prime_bools[i])
            {
                continue;
            }
            for (int j = r; j >= 1; j--)
            {
                if (prime_bools[j])
                {
                    break;
                }
                if (!prime_bools[i] && !prime_bools[j] && i + j <= r && i + j >= l && gcd(i, j) != 1)
                {
                    ans = {i, j};
                    break;
                }
            }
        }

        if (ans.first == -1 || ans.second == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans.first << " " << ans.second << endl;
        }
    }
    return 0;
}