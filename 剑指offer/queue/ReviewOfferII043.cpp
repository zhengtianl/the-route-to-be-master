//
// Created by StarkLu on 2023/2/27.
//
#include "Tree.h"
#include "iostream"
#include "queue"
using namespace std;


class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        this->root = root;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
            if (!(node->left && node->right)) {
                candidate.push(node);
            }
        }
    }

    int insert(int val) {
        TreeNode* child = new TreeNode(val);
        TreeNode* node = candidate.front();
        int ret = node->val;
        if (!node->left) {
            node->left = child;
        }
        else {
            node->right = child;
            candidate.pop();
        }
        candidate.push(child);
        return ret;
    }

    TreeNode* get_root() {
        return root;
    }

private:
    queue<TreeNode*> candidate;
    TreeNode* root;
};

