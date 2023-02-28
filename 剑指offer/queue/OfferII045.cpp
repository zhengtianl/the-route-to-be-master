//
// Created by StarkLu on 2023/2/28.
//
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
#include "tree.h"
using namespace std;
class Solution {
public:
    void dfs(TreeNode *root, int height, int &ans, int &curHeight)
    {
        if(root == nullptr){
            return;
        }
        height++;
        dfs(root -> left, height, ans, curHeight);
        dfs(root -> right, height, ans, curHeight);
        if(height > curHeight){
            curHeight = height;
            ans = root -> val;
        }

    }



    int findBottomLeftValue(TreeNode* root) {
        int ans;
        int curHeight = 0;
        if(root == nullptr){
            return{};
        }
        dfs(root,0,ans,curHeight);
        return ans;

    }
};