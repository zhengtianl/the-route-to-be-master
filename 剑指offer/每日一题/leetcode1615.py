from typing import List
class solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        g = [[0] * n for _ in range(n)]
        cnt = [0] * n
        for a, b in roads:
            g[a][b] = g[b][a] = 1
            cnt[a] += 1
            cnt[b] += 1
        return max(cnt[a] + cnt[b] - g[a][b] for a in range(n) for b in range(a+1, n))
if __name__ == '__main__':
    roads = [[0,1],[0,3],[1,2],[1,3]]
    n = 4
    sol = solution()
    print(sol.maximalNetworkRank(n, roads))

    