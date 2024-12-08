#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; // number of test cases
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        int teacher1, teacher2;
        cin >> teacher1 >> teacher2;

        int david;
        cin >> david;

        // Sorting the positions of the two teachers
        if (teacher1 > teacher2) swap(teacher1, teacher2);

        // Calculate the distances between David and both teachers
        int dist1 = abs(david - teacher1);
        int dist2 = abs(david - teacher2);

        // The optimal number of moves is determined by the maximum of the two distances
        int result = max(dist1, dist2);
        cout << result << endl;
    }

    return 0;
}
