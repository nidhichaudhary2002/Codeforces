#include <iostream>
using namespace std;

bool isComposite(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return true;
        }
    }
    return false;
}

pair<int, int> findCompositeIntegers(int n)
{

    for (int i = 1; i < 1000000000; i++)
    {
        int a = i;
        int b = n + a;
        if (isComposite(a) && isComposite(b))
        {
            return make_pair(b, a);
        }
    }

    return {-1, -1};
}

int main()
{
    int n;
    cin >> n;

    pair<int, int> result = findCompositeIntegers(n);

    cout << result.first << " " << result.second << endl;

    return 0;
}
