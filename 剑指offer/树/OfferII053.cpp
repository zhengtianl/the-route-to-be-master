/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "Tree.h"
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {    
        TreeNode* preNode = nullptr;
        TreeNode* ret = nullptr;
        if(root == nullptr) return nullptr;
        return helper(root, p, preNode ,ret);
    }
    TreeNode* helper(TreeNode* root, TreeNode* target, TreeNode*& preNode, TreeNode*& ret)
    {
        if(root == nullptr) return nullptr;
        helper(root -> left, target, preNode, ret);
        if(preNode == target)
        {
            ret = root;
        }
        preNode = root;
        helper(root -> right, target, preNode, ret);
        return ret;
    }
};