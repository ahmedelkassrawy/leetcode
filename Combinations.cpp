class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& subset, int n, int k, int start) {
        // Base Case: If subset size == k, add to result
        if (subset.size() == k) {
            res.push_back(subset);
            return;
        }

        // Loop from 'start' to 'n' to generate combinations
        for (int i = start; i <= n; i++) {
            subset.push_back(i);
            backtrack(res, subset, n, k, i + 1); // Move to the next number
            subset.pop_back(); // Backtrack to explore other options
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(res, subset, n, k, 1);
        return res;
    }
};
