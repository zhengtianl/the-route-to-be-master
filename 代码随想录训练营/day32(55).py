class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        far_distance = 0
        i = 0
        while i <= far_distance:
            far_distance = max(far_distance, i + nums[i])
            if far_distance >= n - 1: return True
            i += 1
        return False

