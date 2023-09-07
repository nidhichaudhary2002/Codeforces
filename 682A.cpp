// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, m, cnt = 0;
//     cin >> n >> m;

//     for (int i = 1; 5 * i < 1000000; i++)
//     {
//         for (int j = 1; j <= min(n, m); j++)
//         {
//             int b = 5 * i - j;
//             if (b <= max(n, m) && b > 0)
//             {
//                 cnt++;
//             }
//         }
//     }

//     cout << cnt;
//     return 0;
// }

#include <iostream>

int main()
{
    long long n, m;
    std::cin >> n >> m;

    // Count numbers in the range [1, n] that are congruent to 0, 1, 2, 3, or 4 modulo 5.
    long long count_mod_5_n[5] = {0};
    for (long long i = 1; i <= n; ++i)
    {
        count_mod_5_n[i % 5]++;
    }

    // Count numbers in the range [1, m] that are congruent to 0, 1, 2, 3, or 4 modulo 5.
    long long count_mod_5_m[5] = {0};
    for (long long i = 1; i <= m; ++i)
    {
        count_mod_5_m[i % 5]++;
    }

    // Calculate the number of valid pairs.
    long long result = count_mod_5_n[0] * count_mod_5_m[0] +
                       count_mod_5_n[1] * count_mod_5_m[4] +
                       count_mod_5_n[2] * count_mod_5_m[3] +
                       count_mod_5_n[3] * count_mod_5_m[2] +
                       count_mod_5_n[4] * count_mod_5_m[1];

    std::cout << result << std::endl;
    return 0;
}
