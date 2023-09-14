class Solution:
    def generateParenthesis(self, n: int):
        ans = []
        def backtrack(s, left, right):
            if len(s) == 2 * n:
                ans.append(s)
                return
            if left < n:
                backtrack(s + '(', left + 1, right)
            if right < left:
                backtrack(s + ')', left, right + 1)
        backtrack('', 0, 0)
        return ans
n = 5
solution = Solution()
nums = solution.generateParenthesis(n)
print(nums)
