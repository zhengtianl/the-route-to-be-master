//
// Created by 45807 on 2023/2/26.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int fn[n+2], bn[n+2];
        fn[0] = 0;
        bn[n+1] = 0;
        for(int i = 1; i <= n; i++) fn[i] = fn[i - 1] + nums[i - 1]; // nums[0]存在所以多一位
        for(int i = n; i > 0; i--) bn[i] = bn[i + 1] + nums[i - 1]; // nums[-1]不存在所以不能到0
        for(int i = 1; i <= n ;i ++) ans.push_back(abs(fn[i-1] - bn[i+1]));
        return ans;
    }

    vector<int> leftRigthDifference2(vector<int>& nums)
    {
        int n = nums.size();
        int left = 0, right = 0;
        for(int i = 1; i < n; i++){
            right += nums[i];
        }
        vector<int> ans = {abs(left - right)};
        for (int i = 1; i < n; i++) {
            left += nums[i-1];
            right -= nums[i];

            ans.push_back(abs(left - right));
        }
        return ans;
    }


};





