from typing import List
class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1: return 0
        ans = 0
        curdistance = 0
        nxtdistance = 0
        n = len(nums)
        for i in range(n):
            nxtdistance = max(nums[i] + i, nxtdistance)
            if i == curdistance:
                ans += 1
                curdistance = nxtdistance
                if nxtdistance >= n - 1: break
        return ans
