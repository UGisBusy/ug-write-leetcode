#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int len = nums[0].size();
        vector<pair<string, int>> trimmed_nums(nums.size());
        vector<int> res;
        for (auto &q : queries) {
            for (int i=0; i<nums.size(); ++i) {
                // trimmed_nums[i].first = stoll(nums[i].substr(len - q[1]));
                trimmed_nums[i].first = nums[i].substr(len - q[1]);
                trimmed_nums[i].second = i;
            }
            sort(trimmed_nums.begin(), trimmed_nums.end(), cmp);
            res.push_back(trimmed_nums[q[0]-1].second);
        }
        return res;
    }

    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        int i = 0;
        while (i < a.first.size()) {
            if (a.first[i] != b.first[i]) {
                return a.first[i] < b.first[i];
            }
            ++i;
        }
        return a.second < b.second;
        // return (a.first != b.first)? a.first < b.first : a.second < b.second;
    }
};
