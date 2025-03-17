class Solution {
public:
    bool can(vector<int>&nums,int k , int capability)
    {
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= capability)
            {
                cnt++;
                i++; //skip the next house gambk
            }
        }

        return cnt >= k;
    }


    int minCapability(vector<int>& nums, int k) 
    {
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());

        while(l < r)
        {
            int mid = l + (r - l) / 2;

            if(can(nums,k,mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        } 

        return l;    
    }
};