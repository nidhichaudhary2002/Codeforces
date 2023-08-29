#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;
    long long horizontal_flagstones = ceil(double(n) / double(a));
    long long vertical_flagstones = ceil(double(m) / double(a));

    long long total_flagstones = horizontal_flagstones * vertical_flagstones;

    // Print the result
    cout << total_flagstones << endl;

    return 0;
}
