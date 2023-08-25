#include <iostream>
#include <vector>

using namespace std;

vector<long long> generateFibonacci()
{
    vector<long long> fib;
    fib.push_back(0);
    fib.push_back(1);
    while (fib.back() < 1000000000LL)
    { 
        long long next = fib[fib.size() - 1] + fib[fib.size() - 2];
        fib.push_back(next);
    }
    return fib;
}

int main()
{
    long long n;
    cin >> n;

    vector<long long> fib = generateFibonacci();
    int size = fib.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            for (int k = j; k < size; k++)
            {
                if (fib[i] + fib[j] + fib[k] == n)
                {
                    cout << fib[i] << " " << fib[j] << " " << fib[k] << endl;
                    return 0;
                }
            }
        }
    }

    cout << "I'm too stupid to solve this problem" << endl;

    return 0;
}
