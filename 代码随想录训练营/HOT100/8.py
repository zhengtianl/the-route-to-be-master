
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []

        nums.sort()
        ans = []
        for k in range(len(nums) - 2):
            if nums[k] > 0:
                return ans

            if k > 0 and nums[k] == nums[k-1]:
                continue

            l = k + 1
            r = len(nums) - 1
            while l < r:
                s = nums[k] + nums[l] + nums[r]
                if s == 0:
                    ans.append([nums[k], nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
                    while l < r and nums[r] == nums[r+1]:
                        r -= 1
                elif s < 0:
                    l += 1
                else:
                    r -= 1

        return ans
            
            
        