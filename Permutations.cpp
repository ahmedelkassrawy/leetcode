class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& subst, vector<int>& nums, vector<bool>& used)
    {
        if(subst.size() == nums.size()) 
        { // Base case: all elements are considered
            res.push_back(subst);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(used[i] == 1) continue; //to get distinct

            used[i] = 1;
            subst.push_back(nums[i]);

            backtrack(res,subst,nums,used); //explore

            used[i] = 0;
            subst.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> subst;
        vector<bool> used(nums.size(), false);
        backtrack(res,subst,nums,used);
        return res;    
    }
};