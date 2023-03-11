/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "../dataStruct.h"
class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode*& root) {
        if(root == nullptr) return nullptr;
        convertBST(root -> right);
        sum += root -> val;
        root -> val = sum;
        convertBST(root -> left);
        return root;
    }
    
};