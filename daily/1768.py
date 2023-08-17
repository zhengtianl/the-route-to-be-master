class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        m, n = len(word1), len(word2)
        i = j = 0

        ans = list()
        while i < m or j < n:
            if i < m:
                ans.append(word1[i])
                i += 1
            if j < n:
                ans.append(word2[j])
                j += 1
        
        return "".join(ans)

