// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// bool isSame(int y)
// {
//     set<int> a;

//     for (int i = 0; i < 4; i++)
//     {
//         a.insert(y % 10);
//         y = y / 10;
//     }

//     if (a.size() != 4)
//     {
//         return false;
//     }
//     return true;
// }

// int main()
// {

//     int n;
//     cin >> n;
//     n++;
//     for (int i = n; i <= 9000; i++)
//     {
//         if (isSame(i))
//         {
//             cout << i;
//             break;
//         }
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include <unordered_set>

bool hasDistinctDigits(int year) {
    std::string yearStr = std::to_string(year);
    std::unordered_set<char> digitSet;

    for (char digit : yearStr) {
        if (digitSet.find(digit) != digitSet.end()) {
            return false;
        }
        digitSet.insert(digit);
    }

    return true;
}

int findNextDistinctYear(int y) {
    int year = y + 1;

    while (true) {
        if (hasDistinctDigits(year)) {
            return year;
        }
        year++;
    }
}

int main() {
    int y;
    std::cin >> y;

    int result = findNextDistinctYear(y);
    std::cout << result << std::endl;

    return 0;
}
