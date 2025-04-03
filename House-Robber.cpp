class Solution {
public:
    vector<int> dp1; 

    int dp(int idx, vector<int>& nums) {
        if (idx >= nums.size()) return 0; 

        if (dp1[idx] != -1) return dp1[idx];
 
        int cnt1 = nums[idx] + dp(idx + 2, nums); //hna5od da wroh llb3ado betneen
        int cnt2 = dp(idx + 1, nums); //hnskip da

        return dp1[idx] = max(cnt1, cnt2);
    }

    int rob(vector<int>& nums) 
    {
        dp1.assign(nums.size(), -1); 
        return dp(0, nums);
    }
};