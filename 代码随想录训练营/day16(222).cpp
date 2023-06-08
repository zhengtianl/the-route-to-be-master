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
using namespace std;
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        int Depth_left = 0;
        int Depth_right = 0;
        while(left){
            left = left -> left;
            Depth_left ++;
        }
        while(right){
            right = right -> right;
            Depth_right ++;
        }
        if(Depth_left == Depth_right){
            return (2 << Depth_left) - 1;
        }
        return countNodes(root -> right) + countNodes(root -> left) + 1;
    }
};