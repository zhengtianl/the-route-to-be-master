/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "DataStruct.h"
#include "vector"
using namespace std;
class Solution {
public:
    TreeNode* travel(vector<int>& nums, int left, int right){
        if (left > right) return nullptr;
        int mid = left + ((right - left) >> 1);
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = travel(nums, left, mid - 1);
        root -> right = travel(nums, mid + 1, right);
        return root;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* res = travel(nums, 0, nums.size() - 1);
        return res;
    }
};