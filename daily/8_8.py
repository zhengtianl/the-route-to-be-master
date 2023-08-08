class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        positiveMax, negativeMin = 0, 0
        positiveSum, negativeSum = 0, 0
        for n in nums:
            positiveSum += n
            positiveMax = max(positiveMax, positiveSum)
            positiveSum = max(0, positiveSum)
        
            negativeSum += n
            negativeMin = min(negativeMin, negativeSum)
            negativeSum = min(0, negativeSum)
        
        return max(positiveMax, -negativeMin)

