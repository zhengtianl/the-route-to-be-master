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
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return sum;
    }

    void dfs(TreeNode *root, int sum){
        if(root == nullptr) return; //递归结束条件
        sum = sum * 10 + root -> val; //状态方程
        if(root -> left == nullptr && root-> right == nullptr){
            this -> sum += sum; //结束条件和返回值
        }
        dfs(root -> left,  sum); //递归左右子树
        dfs(root -> right, sum);
    }

    int dfs1(TreeNode* root, int num){
        if(root == nullptr) return 0; //递归结束条件
        num = num * 10 + root -> val;
        if (root ->left == nullptr && root -> right == nullptr){
             return num; //返回值
        }
        return dfs1(root ->left, num) + dfs1(root -> right, num); //返回值
    }

private:
    int sum = 0;

};

