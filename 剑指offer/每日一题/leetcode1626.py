class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        people = sorted(zip(scores, ages))
        dp = [0] * len(scores)
        ans = 0
        for i in range(len(scores)):
            for j in range(i):
                if people[i][1] >= people[j][1]:
                    dp[i] = max(dp[i], dp[j])
            dp[i] += people[i][0]
            ans = max(ans, dp[i])
        return ans