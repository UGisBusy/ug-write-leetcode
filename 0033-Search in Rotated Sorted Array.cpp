#include <bits/stdc++.h>
using namespace std;

/*
113.03/18
跑兩次二分搜
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int offset = find_pivot(nums);
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(target == nums[(mid + offset) % size]){
                return (mid + offset) % size;
            }
            else if(target < nums[(mid + offset) % size]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return -1;
    }

    int find_pivot(vector<int>& nums){
        int left = 0;
        int right = nums.size() - 1;
        while(nums[left] > nums[right]){
            int mid = (left + right) / 2;
            if(nums[left] > nums[mid]){
                left++;
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << sol.search(nums, target) << endl;
    return 0;
}