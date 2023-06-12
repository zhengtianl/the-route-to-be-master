#include "iostream"
#include "vector"
#include "DataStruct.h"
using namespace std;
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
class Solution {
public:
    vector<int> res;
    bool isValidBST(TreeNode* root) {
        res = travel(root);
        for(int i = 0; i < res.size() - 1; i++){
            if(res[i] >= res[i+1]){
                return false;
            }
        }
        return true;

    }

    vector<int> travel(TreeNode* root){
        if (root == nullptr) return res;
        travel(root -> left);
        res.push_back(root -> val);
        travel(root -> right);
        return res;
    }
};