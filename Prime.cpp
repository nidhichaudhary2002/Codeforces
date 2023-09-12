#include <bits/stdc++.h>
#define orz 0
#define ll long long
#define MAXN 1000005
#define MAXM 200005
#define MOD 998244353
using namespace std;

inline int read()
{
    int f = 1, k = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        k = k * 10 + c - '0', c = getchar();
    if (f)
        return k;
    return -k;
}
int t, n, ans;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int main()
{
    t = read();
    while (t--)
    {
        int l = read(), r = read();
        if (l == r)
        {
            if (l % 2 == 1)
            {
                bool f = 0;
                for (int i = 3; i <= sqrt(l); i++)
                {
                    if (l % i != 0)
                        continue;
                    printf("%d %d\n", i, l - i);
                    f = 1;
                    break;
                }
                if (!f)
                {
                    printf("-1\n");
                }
                continue;
            }
            if (l == 2)
            {
                printf("-1\n");
                continue;
            }
            printf("%d %d\n", l / 2, l / 2);
        }
        else
        {
            if (r % 2 == 1)
                r--;
            if (r == 2)
            {
                printf("-1\n");
                continue;
            }
            printf("%d %d\n", r / 2, r / 2);
        }
    }
    return orz;
}