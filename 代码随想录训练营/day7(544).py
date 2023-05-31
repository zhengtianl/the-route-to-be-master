class Solution:
    def reverseStr(self, s: str, k:int) -> str:
        n = len(s)
        for i in range(0, n, 2*k):
            if i + k <= n:
                s = s[:i] + s[i:i+k][::-1] + s[i+k:]
            else:
                s = s[:i] + s[i:][::-1]
        return s