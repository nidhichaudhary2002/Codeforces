#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const long long p = 1e9 + 7;

long long powMod(long long x, long long q) {
    if (q == 0) return 1;
    long long i = powMod(x, q / 2);
    if (q % 2 == 0) return (i * i) % p;
    return (i * i % p) * x % p;
}

void solve() {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    unordered_map<long long, long long> hs;

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        hs[a[i]]++;
    }

    long long ans = 0;
    for (auto &entry : hs) {
        long long x = entry.first;
        long long y = entry.second;
        long long l = min(m / x, y);
        ans = max(ans, (long long)l * x);

        if (hs.find(x + 1) == hs.end()) continue;

        long long z = hs[x + 1];
        for (long long i = 1; i <= y; i++) {
            if (i * x > m) break;
            long long du = m - i * x;
            long long su = min(du / (x + 1), z) * (x + 1) + i * x;
            ans = max(ans, su);
        }
    }

    cout << ans << endl;
}

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
    return 0;
}

