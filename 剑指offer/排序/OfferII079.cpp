//
// Created by StarkLu on 2023/3/12.
//
#include "vector"
using namespace std;
class Solution {
public:
    vector<vector<int>> dfs(int cur, vector<int>& nums){
        if(cur == nums.size()){
            return vector<vector<int>>{{}};
        }
        vector<vector<int>> res;
        vector<vector<int>> subres = dfs(cur + 1, nums);
        for(const auto& subset: subres){
            res.push_back(subset);
            vector<int> new_subset(subset);
            new_subset.push_back(nums[cur]);
            res.push_back(new_subset);
        }
        return res;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        return dfs(0, nums);
    }
};