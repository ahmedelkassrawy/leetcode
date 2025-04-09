class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i = n - 1; i >= 0;i--)
        {
            if(mp.find(nums[i]) != mp.end()) ///rakm leh wgood m3ana
            {
                return i / 3 + 1;
            }

            //mlhoosh wgood 5las 
            mp[nums[i]]++;
        }

        return 0;    
    }
};

//ehna hnmshy mn array mn wra wnshoof lw hey2ablna ay rakm m3ana 2abl kda 
//yb2a duplicate wlazm nrg3 i / 3 + 1 (formula ethasbt)
//else we could easily add them as a new element in the mp