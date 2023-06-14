//
// Created by StarkLu on 2023/6/13.
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
#include "iostream"
#include "vector"
using namespace std;

class Solution {
private:
    vector<int> res;
    void travel(TreeNode* root){
        if(root == nullptr) return;
        travel(root -> left);
        res.push_back(root -> val);
        travel(root -> right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        travel(root);
        for(int i = 0; i < res.size() - 1; i++){
            ans = min(ans, abs(res[i + 1] - res[i]));
        }
        return ans;
    }
};