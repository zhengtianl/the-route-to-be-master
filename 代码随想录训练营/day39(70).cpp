//
// Created by StarkLu on 2023/6/30.
//
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+2];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n + 2; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};