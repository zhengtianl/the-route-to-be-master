class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        used = [False] * len(nums)
        self.backtracking(nums, [], res, used)
        return res

    def backtracking(self, nums, path, res, used):
        #如果是路径长度等于数组长度就说明找了答案
        if len(path) == len(nums):
            res.append(path[:])
            return

        for i in range(0, len(nums)):
            if used[i]:
                continue

            path.append(nums[i])
            used[i] = True #树枝去重
            self.backtracking(nums, path, res, used)
            used[i] = False #树枝去重
            path.pop()

