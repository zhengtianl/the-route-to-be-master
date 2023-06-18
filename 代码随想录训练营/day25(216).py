class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        path = []
        self.helper(0, n,k,res,path,1)
        return res

    def helper(self, currentSum, targetSum, k, res, path, startIndex):
        if targetSum < currentSum:
            return
        if targetSum == currentSum and len(path) == k:
            res.append(path[:])
            return

        for i in range(startIndex,10):
            currentSum += i
            path.append(i)
            self.helper(currentSum, targetSum, k, res, path, i
                        +1)
            currentSum -= i
            path.pop()