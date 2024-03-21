#include <bits/stdc++.h>
using namespace std;

/*
inorder traversal of a binary search tree is a sorted array


*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    };

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> result;
        vector<int> values;
        balance(root, values);
        for (auto &q : queries) {
            int left = 0;
            int right = values.size() - 1;
            while (left <= right) {
                int mid = (right + left) / 2;
                if (values[mid] == q) {
                    left = mid;
                    break;
                }
                else if (values[mid] < q) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if (left == values.size()) {
                left--;
            }
            if (values[left] == q) {
                result.push_back({q, q});
            }
            else if (values[left] > q) {
                if (left - 1 >= 0) {
                    result.push_back({values[left - 1], values[left]});
                }
                else {
                    result.push_back({-1, values[left]});
                }
            }
            else {
                if (left + 1 < values.size()) {
                    result.push_back({values[left], values[left + 1]});
                }
                else {
                    result.push_back({values[left], -1});
                }
            }
        }
        return result;
    }

    void balance(TreeNode* root, vector<int>& nodes) {
        if (root->left) {
            balance(root->left, nodes);
        }
        nodes.push_back(root->val);
        if (root->right) {
            balance(root->right, nodes);
        }
    }

};