class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        for (int i = 0; i < n; i++)
        {
            if(nums1[m+i] == 0) nums1[m + i] = nums2[i];
            else continue;
        }
        
        sort(nums1.begin(), nums1.end()); 
    }
};