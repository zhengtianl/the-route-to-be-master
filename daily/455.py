class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        n = len(g)
        m = len(s)
        res = 0
        i = j = 0
        while i < n and j < m:
            if s[j] < g[i]:
                j += 1
            elif s[j] >= g[i]:
                res += 1
                i += 1
                j += 1
        return res            
        