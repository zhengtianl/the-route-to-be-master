class Solution:
    def isPalindrome(self, s):

        return s[::-1] == s[:]

    def backtracking(self, s, start_index, path, result):
        if start_index == len(s):
            result.append(path[:])
            return

        for i in range(start_index, len(s)):
            if self.isPalindrome(s[start_index:i+1]):
                path.append(s[start_index:i+1])
                self.backtracking(s, i+1, path, result)
                path.pop()

    def partition(self, s: str) -> List[List[str]]:
        result = []
        self.backtracking(s, 0, [], result)
        return result