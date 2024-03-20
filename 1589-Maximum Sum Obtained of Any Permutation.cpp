#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> heat_map(nums.size(), 0);
        for (auto &request : requests) {
            heat_map[request[0]]++;
            if (request[1] + 1 < heat_map.size()) {
                heat_map[request[1] + 1]--;
            }
        }
        for (int i = 1; i < heat_map.size(); i++) {
            heat_map[i] += heat_map[i-1];
        }
        sort(nums.begin(), nums.end(), greater<int>());
        sort(heat_map.begin(), heat_map.end(), greater<int>());
        uint64_t sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += (uint64_t)nums[i] * heat_map[i];
        }
        return sum % 1000000007;
    }
};