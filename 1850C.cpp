#include <iostream>
#include <vector>
#include <string>

using namespace std;

string find_vertical_word(const vector<string> &grid)
{
    string word;

    for (int col = 0; col < 8; col++)
    {
        for (int row = 0; row < 8; row++)
        {
            if (grid[row][col] != '.')
            {
                word.push_back(grid[row][col]);
            }
        }
    }

    return word;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<string> grid(8);
        for (int i = 0; i < 8; i++)
        {
            cin >> grid[i];
        }

        string result = find_vertical_word(grid);
        cout << result << endl;
    }

    return 0;
}
