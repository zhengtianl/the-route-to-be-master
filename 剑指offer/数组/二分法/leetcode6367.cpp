//
// Created by StarkLu on 2023/2/26.
//
#include<iostream>
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int ans = 0;
        int n = nums.size();
        for(int r = (n + 1)/2; r < n; r ++){
            if (nums[l] * 2 <= nums[r]){
                ans += 1;
                l ++;
            }
        }
        return ans * 2;
        }
};

