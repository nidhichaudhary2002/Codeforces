#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int N, vector<int> &A, vector<int> &B)
{
    int minExpenditure = 0;
    int remainingChemical = 0;

    for (int i = 0; i < N; ++i)
    {
        minExpenditure += max(A[i] * B[i] - remainingChemical, 0);
        remainingChemical = max(remainingChemical - A[i] * B[i], 0);
    }

    return minExpenditure;
}

int main()
{
    int N;
    cin >> N; // Number of array elements

    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i]; // Cost of chemical per unit on each day
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> B[i]; // Required quantity of chemical on each day
    }

    int result = solve(N, A, B);
    cout << result << endl;

    return 0;
}
