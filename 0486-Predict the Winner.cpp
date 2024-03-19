#include <bits/stdc++.h>
class Solution
{
public:
    bool sol(vector<int> &nums, int left, int right, int s, int turn)
    {
        if (left == right)
        {
            return (s + nums[left] * turn) >= 0;
        }
        if (turn == 1)
        {
            return sol(nums, left + 1, right, s + nums[left] * turn, turn * -1) ||
                   sol(nums, left, right - 1, s + nums[right] * turn, turn * -1);
        }
        else
        {
            return sol(nums, left + 1, right, s + nums[left] * turn, turn * -1) &&
                   sol(nums, left, right - 1, s + nums[right] * turn, turn * -1);
        }
    }

    bool predictTheWinner(vzector<int> &nums)
    {
        return sol(nums, 0, nums.size() - 1, 0, 1);
    }
};