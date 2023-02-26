//
// Created by 45807 on 2023/2/26.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> ans;
        int n= nums.size();
        int f[n+2], g[n+2];
        f[0] = 0, g[n+1] = 0;
        for(int i = 1; i <= n; i++) f[i] = f[i - 1] + nums[i - 1]; //前缀和
        for(int i = n; i > 0; i++) g[i] = g[i + 1] + nums[i - 1]; //后缀和

        for(int i = 1; i < n; i++) ans.push_back(abs(f[i-1] - g[i+1]));
        return ans;
    }
};