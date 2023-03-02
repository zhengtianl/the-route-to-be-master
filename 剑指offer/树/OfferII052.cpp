//
// Created by StarkLu on 2023/3/2.
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
#include "Tree.h"
#include "iostream"
using namespace std;
class Solution {
public:
    void inOrdered(TreeNode* root, vector<int> &res)
    {
        if(root == nullptr) return;
        inOrdered(root -> left, res);
        res.push_back(root -> val);
        inOrdered(root -> right, res);
    }


    TreeNode* increasingBST(TreeNode* root) {
        vector<int> res;
        inOrdered(root, res);
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* cur = dummy;
        for(auto num: res)
        {
            cur -> right =new TreeNode(num);
            cur = cur -> right;
        }
        return dummy -> right;

    }
};