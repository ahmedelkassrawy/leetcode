class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int min_length = INT_MAX;  // Initialize with a large value
        int total = 0;            // Sum of the current subarray
        int start = 0;            // Left pointer of the sliding window

        for (int end = 0; end < nums.size(); ++end) 
        {
            total += nums[end];  // Add the current element to the total

            // Shrink the window while the sum is greater than or equal to the target
            while (total >= target) 
            {
                min_length = min(min_length, end - start + 1);
                total -= nums[start];  // Remove the leftmost element
                start++;               // Move the left pointer forward
            }
        }

        // If no valid subarray is found, return 0
        return (min_length == INT_MAX) ? 0 : min_length;
    }
};
