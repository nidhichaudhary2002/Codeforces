#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<int> skills(n);
    for (int j = 0; j < n; j++) {
      cin >> skills[j];
    }

    int max_size = 0;
    for (int size = 1; size <= n; size++) {
      bool is_valid = true;
      for (int j = 0; j < n; j++) {
        if (skills[j] == skills[j + size]) {
          is_valid = false;
          break;
        }
      }

      if (is_valid) {
        max_size = size;
        break;
      }
    }

    cout <<" Ans : " << max_size << endl;
  }

  return 0;
}