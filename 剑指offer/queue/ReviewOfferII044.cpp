//
// Created by StarkLu on 2023/2/28.
//

#include  "queue"
#include "vector"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode *right): val(x), left(left), right(right){}
};


using namespace std;

class Solution{
public:
    Solution(){};
    ~Solution(){};
    void dfs(vector<int>& res,TreeNode* node, int curHeight){
        if(res.size() == curHeight){
            res.push_back(node  -> val);
        }else{
            res[curHeight] = max(res[curHeight], node -> val);
        }
        if(node -> left){
            dfs(res, node -> left, curHeight + 1);
        }
        if(node -> right){
            dfs(res, node -> right, curHeight + 1);
        }
    }

    vector<int> largestValues(TreeNode* root) {
        if(root== nullptr){
            return {};
        }
        vector<int> res;
        dfs(res, root, 0);
        return res;
    }
};

