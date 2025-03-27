class Solution {
public:
    void dfs(vector<vector<char>>& board,int i, int j,int n,int m)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;

        board[i][j] = '#';
        
        dfs(board,i + 1,j,n,m);
        dfs(board,i - 1,j,n,m);
        dfs(board,i,j + 1,n,m);
        dfs(board,i,j - 1,n,m);
    }

    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();

        if(m == 0) return;

        for(int i = 0; i < m;i++)
        {
            if(board[i][0] == 'O')
            {
                dfs(board,i,0,n,m);
            }
            if(board[i][n - 1] == 'O')
            {
                dfs(board,i,n-1,n,m);
            }
        }

        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 'O')
            {
                dfs(board,0,j,n,m);
            }
            if(board[m - 1][j] == 'O')
            {
                dfs(board,m - 1,j,n,m);
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};