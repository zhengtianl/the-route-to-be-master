class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        path = []
        self.helper(candidates, target, 0, 0, res, path)
        return res

    def helper(self, candidates, targetSum, currentSum, startIndex, res, path):
        if targetSum == currentSum:
            res.append(path[:])
            return
        for i in range(startIndex, len(candidates)):
            num = candidates[i]
            if currentSum + num > targetSum:
                continue
            currentSum += num
            path.append(num)
            self.helper(candidates, targetSum, currentSum, i, res, path)
            currentSum -= num
            path.pop()
