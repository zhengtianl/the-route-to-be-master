from typing import List
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        diff = 0
        preDiff = 0
        res = 1
        for i in range(1, n):
            diff = nums[i] - nums[i-1]
            if (preDiff <= 0 and diff > 0) or (preDiff >= 0 and diff < 0):
                res += 1
                preDiff = diff
        return res