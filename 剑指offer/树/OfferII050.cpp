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
#include "iostream"
#include "../dataStruct.h"
using namespace std;
class Solution {
public:
    int pathSum(TreeNode* root, long long targetSum)
    {
        if(root == nullptr) return 0;
        return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int dfs(TreeNode* root, long long targetSum)
    {

        if(!root) return 0;
        long long  ans = root -> val == targetSum ? 1 : 0;
        ans += dfs(root -> left, targetSum - root -> val);
        ans += dfs(root -> right, targetSum - root -> val);
        return ans;
    }

};