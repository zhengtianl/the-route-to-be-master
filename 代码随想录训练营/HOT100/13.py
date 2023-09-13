import heapq
from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums)
        hp = []
        for k, v in cnt:
            heapq.heappush(hp, (-v, k))
            while len(hp) > k:
                heapq.heappop(hp)
        return [x.key() for x in hp]