class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp (n + 1,vector<int>(m + 1,0));

        //base cases
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n;i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j], //delete
                        dp[i][j - 1], //insert
                        dp[i - 1][j - 1] //replace
                    });
                }
            }
        }

        // Commented DP table for word1 = \abd\, word2 = \acd\
        /*
               ''  a  c  d
            ----------------
        '' |  0  1  2  3
         a |  1  0  1  2
         b |  2  1  1  2
         d |  3  2  2  1
        */
        
        return dp[n][m];
    }
};