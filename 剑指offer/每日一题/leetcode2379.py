class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        n  = len(blocks)
        ans = n
        for i in range(0, n - k + 1):
            count = 0
            for j in range(i, i + k):
                if blocks[i] == 'W':
                    count += 1
        ans = min(n, count)
        return ans
    