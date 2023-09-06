class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        hashtable = {}
        n = len(s)
        ans = 0
        for right in range(n):
            if s[right] in hashtable:
                left = max(left, hashtable[right] + 1)
        
            hashtable[s[right]] = right
            ans = max(ans, right - left + 1)
        return ans
        
            
        
    