
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        path = []
        self.backTracking(nums, 0,res, path)
        return res

    def backTracking(self, nums, startIndex, res, path):
        res.append(path[:])
        if(startIndex >= len(nums)):
            return
        for i in range(startIndex, len(nums)):
            path.append(nums[i])
            self.backTracking(nums,i+1,res,path)
            path.pop()


