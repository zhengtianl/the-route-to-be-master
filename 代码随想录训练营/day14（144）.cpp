//
// Created by StarkLu on 2023/6/6.
//
#include "vector"
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode *root, vector<int> &res){
        while(root == nullptr) return;
        res.push_back(root -> val);
        preorder(root -> left, res);
        preorder(root -> right, res);

    }
};