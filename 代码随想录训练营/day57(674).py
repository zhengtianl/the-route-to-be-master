class Solution:
    def countSubstrings(self, s: str) -> int:
        dp = [[False] * len(s) for _ in range(len(s))]
        result = 0
        for i in range(len(s)-1, -1, -1): #注意遍历顺序
            for j in range(i, len(s)):
                if s[i] == s[j] and (j - i <= 1 or dp[i+1][j-1]): 
                    result += 1
                    dp[i][j] = True
        return result