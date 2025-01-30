class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) 
        {
            int a = nums[i];

            if (i > 0 && a == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;

            while (l < r) 
            {
                int sum = a + nums[l] + nums[r];

                if (sum > 0) 
                {
                    r--;
                } 
                else if (sum < 0) 
                {
                    l++; 
                } 
                else 
                {
                    res.push_back({a, nums[l], nums[r]}); 
                    while (l < r && nums[l] == nums[l + 1]) l++; //duplicate find
                    l++;
                    r--;
                }
            }
        }

        return res; 
    }
};
