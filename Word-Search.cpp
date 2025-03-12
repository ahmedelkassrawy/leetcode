class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] = word[0] && back(board,word,visited,i,j,0)) return true;
            }
        }

        return false;
    }
    
private:
    bool backtrack(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int index) 
    {
        if (index == word.length()) return true;

        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[index]) 
            return false;

        visited[i][j] = true;

        bool found = backtrack(board, word, visited, i + 1, j, index + 1) ||
                     backtrack(board, word, visited, i - 1, j, index + 1) ||
                     backtrack(board, word, visited, i, j + 1, index + 1) ||
                     backtrack(board, word, visited, i, j - 1, index + 1);

        visited[i][j] = false;  // Backtrack
        
        return found;
    }
};
