#include <iostream>
#include <vector>
#include <set>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int l, r;
    cin >> l >> r;
    
    vector<int> nums;
    for (int i = l; i <= r; i++) {
        nums.push_back(i);
    }

    int cnt = 0;
    while (nums.size() >= 3) {
        bool found = false;
        // Try every triplet (a, b, c) in nums
        for (int i = 0; i < nums.size() && !found; i++) {
            for (int j = i + 1; j < nums.size() && !found; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    int a = nums[i], b = nums[j], c = nums[k];
                    if (gcd(a, b) == 1 && gcd(b, c) == 1 && gcd(a, c) == 1) {
                      
                        nums.erase(nums.begin() + k);
                        nums.erase(nums.begin() + j);
                        nums.erase(nums.begin() + i);
                        cnt++;
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found) break; // No valid triplets found, break out of the loop
    }

    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
