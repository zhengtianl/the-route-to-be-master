#include "iostream"
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int left_height = get_height(root -> left);
        int right_height = get_height(root -> right);
        if (abs(left_height - right_height) > 1) return false;
        return isBalanced(root -> left) && isBalanced(root -> right);
    }

    int get_height(TreeNode* root){
        if(root == nullptr) return 0;
        //单层逻辑
        int left_height = get_height(root -> left);
        int right_height = get_height(root -> right);

        return (max(left_height, right_height) + 1);
    }
};

