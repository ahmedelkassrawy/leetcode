#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(int r, int c, set<pair<int, int>>& vis, vector<vector<int>>& heights, int prevheight) {
        if (vis.count({r, c}) || r < 0 || c < 0 || r >= rows || c >= cols || heights[r][c] < prevheight) {
            return;
        }

        vis.insert({r, c});

        for (auto &dir : directions) {
            dfs(r + dir[0], c + dir[1], vis, heights, heights[r][c]);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        set<pair<int, int>> pac, atl;

        // Start DFS from the Pacific and Atlantic edges
        for (int r = 0; r < rows; r++) {
            dfs(r, 0, pac, heights, heights[r][0]);         // Left border (Pacific)
            dfs(r, cols - 1, atl, heights, heights[r][cols - 1]); // Right border (Atlantic)
        }

        for (int c = 0; c < cols; c++) {
            dfs(0, c, pac, heights, heights[0][c]);         // Top border (Pacific)
            dfs(rows - 1, c, atl, heights, heights[rows - 1][c]); // Bottom border (Atlantic)
        }

        vector<vector<int>> res;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pac.count({r, c}) && atl.count({r, c})) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};
