class Solution {
private:
    vector<int> dp;
    int go(int i,int n)
    {
        if(i == n) return 1;
        if(i > n) return 0;

        if(dp[i] != -1) return dp[i];
        
        int op1 = go(i + 1,n);
        int op2 = go(i + 2,n);

        return dp[i] = op1+op2;
    }
public:
    int climbStairs(int n) 
    {
        dp.assign(n + 1, -1);
        return go(0,n);
    }
};