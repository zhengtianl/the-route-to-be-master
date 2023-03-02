//
// Created by StarkLu on 2023/3/1.
//

#ifndef 剑指OFFER_TREE_H
#define 剑指OFFER_TREE_H

#endif //剑指OFFER_TREE_H


struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};