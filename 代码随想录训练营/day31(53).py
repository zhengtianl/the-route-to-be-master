from typing import List
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        ans = -99999999
        sum = 0
        for i in range(n):
            sum += nums[i]
            ans = max(sum,ans)
            sum = max(sum,0)
        return ans
    def maxSubArray1(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n
        if n == 0: return 0
        dp[0] = nums[0]
        result = dp[0]
        for i in range(1,n):
            dp[i] = max(dp[i - 1] + nums[i], nums[i])
            if (dp[i] > result): result = dp[i]
        return result