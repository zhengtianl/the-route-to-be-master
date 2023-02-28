//
// Created by 45807 on 2023/2/26.
//
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int ans  = 0;
        int n = nums.size();
        for(int j = (n + 1) / 2; j < n; j++){
            if(nums[l] * 2 <= nums[j]){
                ans += 1;
                l++;
            }
        }
        return ans * 2;
    }
};