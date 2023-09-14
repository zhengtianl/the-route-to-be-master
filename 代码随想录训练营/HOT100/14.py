class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        n = len(s)
        hashtable = {}
        ans = 0
        for right in range(n):
            if s[right] in hashtable:
                left = max(left, right)
            hashtable[s[right]] = right
            ans = max(ans, right - left + 1)
        return ans
s1 = 'abcabcbb'
s2 = 'bbbbb'
print(Solution().lengthOfLongestSubstring(s2))