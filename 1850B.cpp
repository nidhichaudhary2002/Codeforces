#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> responses;
        int a, b;
        int max_quality = -1;
        int winner_index = -1;

        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            responses.push_back(make_pair(a, b));

            if (a <= 10 && b > max_quality)
            {
                max_quality = b;
                winner_index = i + 1;
            }
        }

        cout << winner_index << endl;
    }

    return 0;
}
