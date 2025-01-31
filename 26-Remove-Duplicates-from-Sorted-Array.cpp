class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int l = 1;
        for(int r = 1; r < nums.size();r++)
        {
            if(nums[r] != nums[r-1]) 
            {
                nums[l] = nums[r];
                l++;
            }
        }
        return l;

        ///[0,1,1,2] --> [0,1,2,_] 
        //so we change it in place if the previous number is not equal to the 
        //current number then we change the number at l to be the same number 
        //at which the r is pointing not r - 1
    }
};
