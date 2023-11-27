import heapq
from collections import Counter

class Solution:
    def topKFrequent(self, nums, k: int):
        cnt = Counter(nums)
        hp = []
        for key, value in cnt.items():
            heapq.heappush(hp, (-value, key))
            while len(hp) > k:
                hp.pop()
        return [x[1] for x in hp]

nums = [1, 2, 2, 3, 4, 4, 5]
solution = Solution()
nums1 = solution.topKFrequent(nums, 3)
print(nums1)

