class Solution:
    def integerBreak(self, n):
        if n <= 3:
            return 1 * (n - 1)  # 对于n小于等于3的情况，返回1 * (n - 1)

        dp = [0] * (n + 1)  # 创建一个大小为n+1的数组来存储最大乘积结果
        dp[1] = 1  # 当n等于1时，最大乘积为1
        dp[2] = 2  # 当n等于2时，最大乘积为2
        dp[3] = 3  # 当n等于3时，最大乘积为3

        # 从4开始计算，直到n
        for i in range(4, n + 1):
            # 遍历所有可能的切割点
            for j in range(1, i // 2 + 1):
                # 计算切割点j和剩余部分(i - j)的乘积，并与之前的结果进行比较取较大值
                dp[i] = max(dp[i], dp[i - j] * dp[j])

        return dp[n]  # 返回整数拆分的最大乘积结果