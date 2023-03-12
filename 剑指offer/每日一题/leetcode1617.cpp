//
// Created by StarkLu on 2023/3/12.
//
#include "vector"
#include "functional"
using namespace std;
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0] - 1, y = e[1] - 1; // 编号改为从 0 开始
            g[x].push_back(y);
            g[y].push_back(x); // 建树
        }

        vector<int> ans(n - 1), in_set(n), vis(n);
        int diameter = 0;

        // 求树的直径
        function<int(int)> dfs = [&](int x) -> int {
            vis[x] = true;
            int max_len = 0;
            for (int y : g[x])
                if (!vis[y] && in_set[y]) {
                    int ml = dfs(y) + 1;
                    diameter = max(diameter, max_len + ml);
                    max_len = max(max_len, ml);
                }
            return max_len;
        };

        function<void(int)> f = [&](int i) {
            if (i == n) {
                for (int v = 0; v < n; ++v)
                    if (in_set[v]) {
                        fill(vis.begin(), vis.end(), 0);
                        diameter = 0;
                        dfs(v);
                        break;
                    }
                if (diameter && vis == in_set)
                    ++ans[diameter - 1];
                return;
            }

            // 不选城市 i
            f(i + 1);

            // 选城市 i
            in_set[i] = true;
            f(i + 1);
            in_set[i] = false; // 恢复现场
        };
        f(0);
        return ans;
    }
};

