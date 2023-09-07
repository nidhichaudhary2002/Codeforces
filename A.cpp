#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void findTwoBases(int p)
{
    for (int a = 2; a < p; a++)
    {
        if (p % a == 0)
        {
            for (int b = a + 1; b <= p; b++)
            {
                if (p % b == 0 && a != b)
                {
                    cout << a << " " << b << endl;
                    return;
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int p;
        cin >> p;

        if (isPrime(p))
        {
            findTwoBases(p);
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}