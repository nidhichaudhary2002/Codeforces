#include <iostream>
#include <vector>
#include <cmath>
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

vector<bool> prime_array(int n)
{
    vector<bool> prime_bools(n + 1, true);
    prime_bools[0] = prime_bools[1] = false;

    for (int i = 2; i <= std::sqrt(n); ++i)
    {
        if (prime_bools[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime_bools[j] = false;
            }
        }
    }

    return prime_bools;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<bool> prime_bools = prime_array(n);

    cout << "Array with prime flags:" << std::endl;

    return 0;
}
