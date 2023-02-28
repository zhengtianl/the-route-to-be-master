//
// Created by StarkLu on 2023/2/27.
//

#ifndef 滑动窗口_TREE_H
#define 滑动窗口_TREE_H

#endif //滑动窗口_TREE_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};