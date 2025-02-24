class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        map<int,int> mp;

        for(int i = 0; i  < nums.size(); i++)
        {
            mp[nums[i]]++;
        }    

        for (auto& pair : mp) 
        {
            if (pair.second > (nums.size() / 2)) 
            {
                return pair.first; // Return the majority element
            }
        }

        return 0;
    }
};