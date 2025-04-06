class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> dp(n,1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(),dp.end());
    }
};

//vector<int> subs;

//for(int num: nums)
// {
//     auto it = lower_bound(subs.begin(),subs.end(),num);

//     //if it not available in subs then push it
//     if(it == subs.end())
//     {
//         subs.push_back(num);
//     }
//     else
//     {
//         //if there is a num that is bigger than in subs bigger than num
//         *it = num; //replace the element with num
//     }
// }

// return sub.size();