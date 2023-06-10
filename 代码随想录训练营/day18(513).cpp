#include "iostream"
#include "vector"
#include "DataStruct.h"
using namespace std;

class Solution{
    public:
    int maxDepth = INT_MIN;
    int result = 0;
    void traversal(TreeNode* root, int depth){
        //递归结束条件当遇到子节点结束
        if (root -> left  == nullptr && root -> right == nullptr){
             if (depth > maxDepth) {
                maxDepth = depth;
                result = root->val;
            }
            return;
        }

        if(root -> left){
            depth ++;
            traversal(root -> left, depth);
            depth --;
        }
        if(root -> right){
            depth ++;
            traversal(root -> right, depth);
            depth --;
        }
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }

};