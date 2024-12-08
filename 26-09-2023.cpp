#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
}


void permutation(vector<int> nums, int st)
{
    if (st >= nums.size())
    {
        print(nums);
        return;
    }

    for (int i = st; i < nums.size(); i++)
    {
        swap(nums[i], nums[st]);
        permutation(nums, st + 1);
        swap(nums[i], nums[st]);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    permutation(nums, 0);
    return 0;
}