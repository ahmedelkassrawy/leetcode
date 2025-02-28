class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int mn = INT_MAX;
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r)
        {

            if(nums[l] < nums[r])
            {
                mn = min(mn , nums[l]);
                break;
            }

            int mid = (r + l) / 2;
            mn = min(mn , nums[mid]);

            if(nums[mid] >= nums[l] && nums[mid] > nums[r])
            {
                //left sorted
                l = mid + 1;
            }
            else 
            {
                r = mid - 1;
            }
        }  

        return mn;
    }
};
