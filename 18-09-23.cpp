#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long 
#define vi vector < int > 
#define sz(a) ((int) (a).size())
#define ll long long 
#define ull unsigned long long
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7;
ll n, k, x;

void Main() {
	cin >> n >> k >> x;
	if(k > n) {
		cout << -1 << '\n';
	} else if(k > x + 1) {
		cout << -1 << '\n';
	} else {
		ll sum = (ll) k * (k - 1) / 2;
		n -= k;
		sum += (k == x ? x - 1 : x) * n;
		cout << sum << '\n';
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t; while(t--) Main();
	return 0;
}
