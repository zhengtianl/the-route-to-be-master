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
#include "vector"
#include "vector"
using namespace std;
class BSTIterator 
{
private:
vector<int> res;
vector<int> inorder(TreeNode* root, vector<int>& res)
{
    if(root == nullptr) return {};
    inorder(root -> left, res);
    res.push_back(root -> val);
    inorder(root -> right, res);
    return res;
}

int index = 0;
vector<int> init;
public:
    BSTIterator(TreeNode* root):
        index(0),
        init(inorder(root, res))
        {}
    
    
    int next() {
        return init[index++];

    }
    
    bool hasNext() {
        return index < init.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */