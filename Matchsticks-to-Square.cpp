class Solution {
private:
    bool backtrack(int idx,vector<int>&matchsticks,vector<int>&sides,int &len)
    {
        if(idx == matchsticks.size()) return true;

        for(int i = 0; i < 4; i++)
        {
            if(sides[i] + matchsticks[idx] <= len)
            {
                sides[i] += matchsticks[idx];

                if(backtrack(idx + 1,matchsticks,sides,len)) return true;

                sides[i] -= matchsticks[idx];
            }
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) 
    {
        int sum = 0;
        for(int i = 0;i < matchsticks.size(); i++)
        {
            sum += matchsticks[i];
        }

        int len = sum / 4;
        vector<int> sides(4,0);

        if((sum / 4) != len)
        {
            return false;
        }

        sort(matchsticks.rbegin(),matchsticks.rend());
        bool b = backtrack(0,matchsticks,sides,len);
        return b;
    }

};