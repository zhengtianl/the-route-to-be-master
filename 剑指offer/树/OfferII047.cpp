//
// Created by StarkLu on 2023/3/1.
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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        root -> left  = pruneTree(root -> left);
        root -> right = pruneTree(root -> right);
        if(root -> left == nullptr && root -> right == nullptr && root -> val == 0){ //左节点和右节点都为空表示遍历到最后一个节点，所有的值为0移除当前子树
            return nullptr;
        }
        return root;

    }
};