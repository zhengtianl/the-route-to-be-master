from typing import List
class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums.sort(key = lambda x: abs(x), reverse=True)
        n = len(nums)
        res = 0
        for i in range(n):
            if nums[i] < 0 and k > 0:
                nums[i] *= -1
                k -= 1

        if k % 2 == 1:
            nums[-1] *= -1
        res = sum(nums)
        return res