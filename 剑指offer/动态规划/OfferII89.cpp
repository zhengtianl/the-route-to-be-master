//
// Created by StarkLu on 2023/3/16.
//
#include "iostream"
#include "vector"
using namespace std;
class Solution{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1};
    cout << s.rob(nums) <<endl;
}