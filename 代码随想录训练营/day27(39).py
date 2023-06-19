
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        path = []
        self.helper(candidates,target,0,0,res, path)
        return res
    def helper(self, array, targetSum, currentSum, startIndex, res, path):
        if targetSum == currentSum:
            res.append(path[:])
            return

        for i in range(startIndex, len(array)):
            num = array[i]
            if num + currentSum > targetSum:
                continue
            currentSum += array[i]
            path.append(array[i])
            self.helper(array,targetSum,currentSum,i,res, path)
            currentSum -= array[i]
            path.pop()
            