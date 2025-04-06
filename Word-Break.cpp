class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        vector<bool> dp(s.size() + 1,false);
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++)
        {
            for(string w : wordDict)
            {
                int start = i - w.length();
                //3ayz a3rf length akbr mn 0 , wlw equal wla la2 ll w
                if(start >= 0 && s.substr(start,w.length()) == w && dp[start])
                {
                    dp[i] = true;
                    break;
                }
            }
        } 
        return dp[s.size()];   
    }
};