//
// Created by StarkLu on 2023/6/7.
//
#include "vector"
#include "queue"
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

class answer{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != nullptr) q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
            int size = q.size();
            vector<int> r1;
            while(size --) {
                TreeNode *node = q.front();
                q.pop();
                r1.push_back(node->val);
                if(root -> left) q.push(root ->left);
                if(root -> right) q.push(root -> right);
            }

            res.push_back(r1);
        }
        return res;
    }
};