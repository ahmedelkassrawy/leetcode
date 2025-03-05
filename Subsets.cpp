class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>&res,vector<int>&subst,int idx)
    {
        //base case
        if(idx == nums.size())
        {
            res.push_back(subst);
            return;
        }

        //include
        backtrack(nums,res,subst,idx + 1);
        subst.push_back(nums[idx]);

        //exclude
        subst.pop_back();
        backtrack(nums,res,subst,idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> subst;
        backtrack(nums,res,subst,0);
        return res;
    }
};