class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n = nums.size();
        int total = 1 << n;

        vector<vector<int>> res;

        for(int mask = 0;mask < total;mask++)
        {
            vector<int> subst;
            for(int i = 0; i< n; i++)
            {
                if(mask & (1 << i))
                {
                    subst.push_back(nums[i]);
                }
            }
            res.push_back(subst);
        }

        return res;

    }
};