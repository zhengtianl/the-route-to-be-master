//
// Created by StarkLu on 2023/6/10.
//
#include "iostream"
#include "DataStruct.h"


class Solution{
    bool traversal(TreeNode* root, int target){
        //确定结束条件
        if (root -> right == nullptr && root -> left == nullptr && target == 0) return true;
        if (root -> right == nullptr && root -> left == nullptr && target != 0) return false;
        //单层递归
        if(root -> left){
            target -= root->left -> val;
            if (traversal(root -> left, target)) return true;
            target += root -> left -> val;
        }
        if(root -> right){
            target -= root -> right -> val;
            if (traversal(root -> right, target)) return true;
            target += root -> right -> val;
        }

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return traversal(root, targetSum);
    }



};