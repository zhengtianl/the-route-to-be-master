class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        s = s[n:] + s[:n]
        return s



s = Solution()
result = s.reverseLeftWords("dasdhasjkhdaskj", 2)
print(result)