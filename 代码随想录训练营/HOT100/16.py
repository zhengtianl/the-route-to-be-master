class Solution:
    def longestValidParentheses(self, s):
        ans = 0
        stack = [-1]
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if stack == []:
                    stack.append(i)
                else:
                    ans = max(ans, i - stack[-1])
        return ans
            