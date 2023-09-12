#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void combination(vector<int> &nums, int target, int sum, int &ans, int idx)
    {
        if (sum == target)
        {
            ans++;
            return;
        }
        if (idx == nums.size())
        {
            return;
        }

        if (target <= nums[idx])
        {
            combination(nums, target, sum + nums[idx], ans, idx + 1);
        }

        combination(nums, target, sum, ans, idx + 1);

        if (target <= nums[idx])
        {
            combination(nums, target, sum + nums[idx], ans, idx);
        }
    }

    int combinationSum4(vector<int> &nums, int target)
    {

        int ans = 0;
        combination(nums, target, 0, ans, 0);
        return ans;
    }
};