
class Solution:
    def isPalindrome(self,s):
        return s[:] == s[::-1]
    def longestPalindrome(self, s):
        res = ''
        for i in range(len(s)):
            start = max(i - len(res) -1, 0)
            temp = s[start: i+1]
            if self.isPalindrome(temp) and len(temp) > len(res):
                res = temp
            else:
                temp = temp[1:]
                if self.isPalindrome(temp) and len(temp) > len(res):
                    res = temp
        return res