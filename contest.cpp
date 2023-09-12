#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        if (l != r) {
            if (r <= 3)
                cout << -1 << '\n';
            else
                cout << r/2 << ' ' << r/2 << '\n';
        } else {
            bool prime = true;
            for (ll i = 2; i*i <= l; i++) {
                if (l % i == 0) {
                    prime = false;
                    cout << i << ' ' << l-i << '\n';
                    break;
                }
            }
            if (prime) cout << -1 << '\n';
        }
    }
}