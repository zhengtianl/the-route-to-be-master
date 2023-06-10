//
// Created by StarkLu on 2023/6/10.
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
#include "DataStruct.h"
#include "vector"
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void ans(TreeNode* root, int count){
        //递归结束条件
        if(root -> left == nullptr && root -> right == nullptr && count == 0){
            result.push_back(path);
            return;
        }
        if (!root->left && !root->right) return;
        if(root -> left){
            path.push_back(root -> left -> val); //加入左节点的值
            count -= root -> left -> val; //减去左节点的值
            ans(root -> left, count);
            path.pop_back();
            count += root -> left -> val;
        }

        if(root -> right){
            path.push_back(root -> right -> val); //加入左节点的值
            count -= root -> right -> val; //减去左节点的值
            ans(root -> right, count);
            path.pop_back();
            count += root -> right -> val;
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        path.clear();
        if(root == nullptr) return result;
        path.push_back(root -> val);
        ans(root, targetSum - root -> val);
        return result;
    }
};