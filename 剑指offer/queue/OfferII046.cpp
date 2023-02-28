//
// Created by StarkLu on 2023/2/28.
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
#include "vector"
#include "tree.h"
#include "iostream"
using namespace std;
class Solution {
public:
    Solution(){
        cout << "construct is called" << endl;
    };
    ~Solution(){
        cout << "deconstruct is called" << endl;
    };

    Solution(const Solution &c){
        cout << "copy construct is called" << endl;
    };
    void dfs(TreeNode *root, int height, vector<int> &ans, int &curHeight)
    {
        if(root == nullptr){
            return;
        }
        if(height > curHeight)
        {
            curHeight = height;
            ans.push_back(root -> val);
        }
        height ++;
        dfs(root -> right, height, ans,curHeight);
        dfs(root-> left, height, ans, curHeight);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int curHeight = -1;
        if(root == nullptr){
            return{};
        }
        dfs(root,0,ans,curHeight);
        return ans;
    }
private:
    int i = 0;
    int j = 1;
};
void test01(){
    Solution s;
    Solution s2(s);
}


int main(){
    test01();
    return 0;
}