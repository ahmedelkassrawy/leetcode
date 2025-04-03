class Solution {
public:
    vector<int> dp1; 

    int dp(int idx, vector<int>& nums, int end) {
        if (idx > end) return 0; 
        if (dp1[idx] != -1) return dp1[idx]; 

        // Rob the current house and skip the next
        int cnt1 = nums[idx] + dp(idx + 2, nums, end);
        int cnt2 = dp(idx + 1, nums, end); //skip the current house

        // Store the result in memo table and return
        return dp1[idx] = max(robCurrent, skipCurrent);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Scenario 1: Rob houses from 0 to n-2 (exclude last house)
        dp1.assign(n, -1);
        int scenario1 = dp(0, nums, n - 2);

        // Scenario 2: Rob houses from 1 to n-1 (exclude first house)
        dp1.assign(n, -1);
        int scenario2 = dp(1, nums, n - 1);

        // Return the maximum of the two scenarios
        return max(scenario1, scenario2);
    }
};

//so now what happens is that we only add the \end\ param in the dp func
//we run the func 2 times , one time inlcuding the last and not the 1st element
//and vice versa