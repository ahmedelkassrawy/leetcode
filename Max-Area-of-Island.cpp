class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;

        grid[i][j] = 0; //visited

        return 1 + dfs(i + 1, j, m, n, grid) 
                 + dfs(i - 1, j, m, n, grid) 
                 + dfs(i, j + 1, m, n, grid) 
                 + dfs(i, j - 1, m, n, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int mx_area = 0;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    mx_area = max(mx_area, dfs(i, j, m, n, grid));
                }
            }
        }
        return mx_area;
    }
};
