//
// Created by StarkLu on 2023/6/8.
//
#include "iostream"
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}

};


class Solution{
public:
    int maxDepth(TreeNode* root){
       if (root == nullptr) return 0;
       return 1 + max(maxDepth(root -> left), maxDepth(root ->right));
    }

};
int main(){
    TreeNode* root = new TreeNode(0);


}


