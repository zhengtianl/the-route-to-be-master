class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res = []
        path = []
        self.backtracking(nums,0, path, res)
        return res

    def backtracking(self, nums, startIndex, path, res):
        #递归结束条件当路径长度大于2 res push进入
        if len(path) > 1:
            res.append(path[:])
            #加上 return 只记录根节点的值不加return记录所有的值
        used = set()
        for i in range(startIndex, len(nums)):
            if (path and nums[i] < path[-1] or nums[i] in used):
                continue
            used.add(nums[i])
            path.append(nums[i])
            self.backtracking(nums, i + 1, path, res)
            path.pop()


