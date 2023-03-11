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
# include "../dataStruct.h"
# include "unordered_map"
# include "unordered_set"
using namespace std;
class Solution {
public:
    unordered_set<int> cnt;
    bool findTarget1(TreeNode* root, int k) 
    {
        if(root == nullptr) return false;
        if(cnt.count(k - root -> val)) return true;
        cnt.insert(root -> val);
        return findTarget1(root -> left, k) || findTarget1(root -> right, k);
    }


};
class Solution2: public Solution{
public:
    vector<int> ans;
    void dfs(TreeNode* root)
    {
        if(!root) return;
        dfs(root -> left);
        ans.push_back(root -> val);
        dfs(root -> right);
    }
    bool findTarget1(TreeNode* root, int k)
    {
        dfs(root);
        int l = 0, r = ans.size() - 1;
        while( l  < r)
        {
            if (ans[l] + ans[r] == k)
            {
                return true;
            }
            else if( ans[l] + ans[r] < k)
            {
                l++;
            }
            else
            {
                r--;
            } 
        }
        return false;
    }
};