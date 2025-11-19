class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int cnt = 0;
        sort(nums.begin(),nums.end());

        unordered_map<int,int> mp;
        
        if(nums.size() == 0) return 0;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i - 1] == nums[i]) continue;
            if(nums[i] != nums[i - 1] + 1)
            {
                mp[i] = cnt;
                cnt = 0;
            }
            else cnt++;
        }

        mp[0] = cnt;

        int mx = mp[0];
        for(int i =0; i < mp.size(); i++)
        {
            if(mp[i] > mx) mx = mp[i];
        }

        return mx + 1;
    }
};