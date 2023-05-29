//
// Created by StarkLu on 2023/5/29.
//
#include "vector"
#include "iostream"
#include "unordered_map"
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); i++){
            auto it = hashtable.find(target - nums[i]);
            if(it != hashtable.end()){
                return {it -> second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
