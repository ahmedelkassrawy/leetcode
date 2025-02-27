// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2; 

            if (nums[mid] == target) return mid;

            // Check if left half is sorted
            if (nums[mid] >= nums[l])  
            {
                if (target >= nums[l] && target < nums[mid])
                //akbar mn awl rakm flarray bs asgr mn nums[mid] 
                {
                    r = mid - 1; // Target is in left half
                }
                else 
                {
                    l = mid + 1; // Target is in right half
                }
            }
            else // Right half is sorted
            {
                if (target > nums[mid] && target <= nums[r])  
                //akbar mn lmid bs asgr mn a5r rkm rkm fy array
                {
                    l = mid + 1; // Target is in right half
                }
                else 
                {
                    r = mid - 1; // Target is in left half
                }
            }
        }
        return -1;
    }
};
