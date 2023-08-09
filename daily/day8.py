class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        m, s = 1, 0
        while n != 0:
            x, n = n % 10, n // 10
            m *= x
            s += x
        return m - s