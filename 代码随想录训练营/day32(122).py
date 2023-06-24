class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        result = 0
        for i in range(1,n):
            result += max(prices[i] - prices[i-1],0)
        return result