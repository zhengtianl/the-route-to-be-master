class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        hashtable = {} #用来记录是否出现过
        ans = 0
        left = 0
        n = len(s)
        for right in range(n):
            #没有出现过就出现过就更新左坐标，没有出现过就更新右坐标
            if s[right] in hashtable:
                left = max(left, hashtable[s[right]] + 1)

            hashtable[s[right]] = right
            ans = max(ans, right - left + 1)
        return ans

