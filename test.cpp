#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve() {
    int n, k;
    i64 x;
    std::cin >> n >> k >> x;
    
    if (x >= 1LL * k * (k + 1) / 2 && x <= 1LL * k * (n + n - k + 1) / 2) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}