class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        int l =0;
        int mx = 0;
        int bitmask = 0;

        for(int r = 0; r < nums.size();r++)
        {
            while((bitmask & nums[r]) != 0)
            {
                bitmask ^= nums[l]; //remove
                l++;
            } 

            bitmask |= nums[r]; //add
            mx = max(mx,r - l + 1);
        }

        return mx;
    }
};