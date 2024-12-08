#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        int numRows, numStrings;
        cin >> numRows >> numStrings;

        vector<int> zeroCount(numRows, 0);
        vector<int> oneCount(numRows, 0);
        vector<int> questionCount(numRows, 0);

        for (int i = 0; i < numStrings; ++i) {
            string line;
            cin >> line;
            for (int j = 0; j < numRows; ++j) {
                if (line[j] == '0') {
                    zeroCount[j]++;
                } else if (line[j] == '1') {
                    oneCount[j]++;
                } else if (line[j] == '?') {
                    questionCount[j]++;
                }
            }
        }

        long long result = 0;
        for (int i = 0; i < numRows; ++i) {
            int zeros = zeroCount[i];
            int ones = oneCount[i];
            int questions = questionCount[i];

            while (questions-- > 0) {
                if (zeros <= ones) {
                    zeros++;
                } else {
                    ones++;
                }
            }

            result += static_cast<long long>(zeros) * ones;
        }

        cout << result << endl;
    }

    return 0;
}
