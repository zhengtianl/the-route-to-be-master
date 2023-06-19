class Solution:
    def travelBacking(self, candidates, targetSum, currentSum, startIndex, res, path):
        if currentSum == targetSum:
            res.append(path[:])
            return

        #如果遇到一样的
        for i in range(startIndex, len(candidates)):
            if i > startIndex and candidates[i] == candidates[i - 1]:
                continue
            if currentSum + candidates[i] > targetSum:
                break

            currentSum += candidates[i]
            path.append(candidates[i])
            self.travelBacking(candidates,targetSum,currentSum,i+1,res,path)
            currentSum -= candidates[i]
            path.pop()

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        path = []
        candidates.sort()
        self.travelBacking(candidates,target,0,0,result,path)
        return result

