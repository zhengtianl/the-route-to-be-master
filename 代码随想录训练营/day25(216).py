
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        path = []
        self.backtracking(n, k, 0, 1, res, path)
        return res

    def backtracking(self, targetSum, k, currentSum, startIndex, res, path):
        if currentSum > targetSum:
            return
        if currentSum == targetSum and len(path) == k:
            res.append(path[:])  # Append a copy of the path
            return
        for i in range(startIndex, 10):
            currentSum += i
            path.append(i)
            self.backtracking(targetSum, k, currentSum, i + 1, res, path)
            currentSum -= i
            path.pop()

