class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int dir[] = {-1, 0, 1, 0, -1};

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0; // Keep track of fresh oranges

        // Count fresh oranges and push rotten ones into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }

        int ans = 0; // Initialize to 0 instead of -1

        while (!q.empty()) {
            int sz = q.size();
            bool rotted = false; // Track if any oranges were rotted in this round

            while (sz--) {
                pair<int, int> p = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int row = p.first + dir[i];
                    int col = p.second + dir[i + 1];

                    if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;  // Reduce fresh count
                        rotted = true;
                    }
                }
            }

            if (rotted) ans++; // Only increase time if an orange was rotted
        }

        return (fresh > 0) ? -1 : ans;
    }
};
