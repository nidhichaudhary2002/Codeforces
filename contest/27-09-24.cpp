#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

// Function to check if it's possible to form decks of size m
bool canFormDecks(const vector<ll>& a, ll n, ll k, ll m) {
    ll extra_needed = 0;
    ll total_decks = 0;
    
    for (ll i = 0; i < n; i++) {
        ll full_decks = a[i] / m;  // How many full decks can we make from this card type
        total_decks += full_decks; // Count the number of full decks we can make
        
        // Calculate if we can fill extra decks with the remaining cards
        ll leftover = a[i] % m;
        if (leftover > 0) {
            extra_needed += (m - leftover);  // How many extra cards we need to complete the deck
            if (extra_needed > k) {
                return false;  // We can't buy enough cards to complete the decks
            }
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; // Number of test cases
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        ll total_cards = 0;

        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            total_cards += a[i];
        }

        // Binary search for the maximum possible size of a deck
        ll low = 1, high = n + k; // The deck size can't exceed n + number of additional cards
        ll answer = 1;

        while (low <= high) {
            ll mid = (low + high) / 2;

            if (canFormDecks(a, n, k, mid)) {
                answer = mid;  // We can form decks of size mid
                low = mid + 1; // Try for a larger deck size
            } else {
                high = mid - 1; // Try for a smaller deck size
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
