//
// Created by StarkLu on 2023/5/25.
//
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size() - 1;
        vector<int> res(nums.size(),0);
        for(int i = 0, j = nums.size() - 1; i <= j;)
        {
            if(nums[i] * nums[i] < nums[j] * nums[j])
            {
                res[k--] = nums[j] * nums[j];
                j --;
            }
            else{
                res[k--] = nums[i] * nums[i];
                i ++;
            }
        }
        return res;
    }
};


