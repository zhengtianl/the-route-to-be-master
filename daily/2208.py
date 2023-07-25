import heapq

class Solution:
    def halveArray(self, nums: List[int]) -> int:
        pq = []
        for num in nums:
            heappush(pq, -num)
        res = 0
        sum1 = sum(nums)
        sum2 = 0
        while sum2 < sum1 / 2:
            x = -heappop(pq)
            sum2 += x / 2
            heappush(pq, -(x / 2))
            res += 1
        return res
