class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(s, 0, path, res);
        return res;
    }

private:
    void backtrack(const string& s, int idx, vector<string>& path, vector<vector<string>>& res) {
        if (idx == s.length()) 
        {
            res.push_back(path);
            return;
        }

        for (int r = idx; r < s.length(); r++) 
        {
            if (isPalindrome(s, idx, r)) 
            {
                path.push_back(s.substr(idx, r - idx + 1));
                backtrack(s, r + 1, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {  // Corrected condition (l < r, not l <= r)
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;  // Return true only after checking all characters
    }
};
