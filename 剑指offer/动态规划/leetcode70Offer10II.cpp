//
// Created by StarkLu on 2023/2/26.
//
class Solution {
public:
    int numWays(int n) {
        int dp[n+2];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
        return dp[n];

    }

    int climbStairs(int n) {
        int dp[n+2];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }

};