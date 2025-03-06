class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& subst, vector<int>& nums, int idx)
    {
        res.push_back(subst); // Add the current subset

        for(int i = idx; i < nums.size(); i++)
        {
            if(i > idx && nums[i] == nums[i - 1]) continue; // Skip duplicates

            subst.push_back(nums[i]);
            backtrack(res, subst, nums, i + 1);
            subst.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> subst;
        sort(nums.begin(),nums.end());
        backtrack(res, subst, nums, 0);
        return res;
    }
};