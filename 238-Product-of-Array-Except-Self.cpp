class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> res(n,1);

        int pre = 1;
        for(int i = 0; i < n;i++)
        {
            res[i] *= pre;
            pre *= nums[i];
        }

        int suff = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            res[i] *= suff;
            suff *= nums[i];
        }

        return res;
    }
};

//[1,2,3,4]
//pre    [1 ,1 ,2,6]
//suf    [24,12,4,1]

//total  [24,12,8,6]