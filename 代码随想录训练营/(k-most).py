import heapq
from collections import Counter
class Word:
    def __init__(self, key, value):
        self.key = key
        self.value = value
    def __lt__(self, other):
        if self.value != other.value:
            return self.value < other.value
        return self.key > other.key



class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums)
        hp = []
        for key, value in cnt.items():
            heapq.heappush(hp, Word(key,value))
            while len(hp) > k:
                heapq.heappop(hp)
        hp.sort(reverse = True)
        return [x.key for x in hp]