class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int l = 0;
        int r = height.size() - 1;
        int mx = 0;

        while(l < r)
        {
            // Calculate the area with the current two lines
            int curr = min(height[l], height[r]) * (r - l);

            mx = max(mx, curr);

            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }  
        
        return mx;  
    }
};