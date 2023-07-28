import time
import functools
class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        mx = 0
        prev = [[] for _ in range(n + 1)]
        for x, y in relations:
            prev[y].append(x)
        
        @lru_cache(None)
        def dp(i: int) -> int:
            cur = 0
            for p in prev[i]:
                cur = max(cur, dp(p))
            cur += time[i - 1]
            return cur
            
        for i in range(1, n + 1):
            mx = max(mx, dp(i))
        return mx