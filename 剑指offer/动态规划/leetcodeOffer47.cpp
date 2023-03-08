class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dfs(grid, memo, 0, 0);
    }

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& memo, int i, int j)
    {
        if(memo[i][j] != -1)
        {
            return memo[i][j];
        }

        int m = grid.size();
        int n = grid[0].size();
        if(i == m - 1 && j == n  - 1)
        {
            memo[i][j] = grid[i][j];
        }
        else if(i == m - 1)
        {
            memo[i][j] = dfs(grid, memo, i, j+1) + grid[i][j];
        }
        else if(j == n - 1)
        {
            memo[i][j] = dfs(grid, memo, i+1, j) + grid[i][j];
        }
        else
        {
            memo[i][j] = max(dfs(grid, memo, i, j+1), dfs(grid, memo, i+1, j)) + grid[i][j];
        }
        return memo[i][j];
    }
};