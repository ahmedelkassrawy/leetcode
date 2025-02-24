class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int,int> mp1;
        map<int,int> mp2;

        for(int i = 0;i < nums1.size(); i++)
        {
            mp1[nums1[i]]++;
        }

        for(int i = 0;i < nums2.size(); i++)
        {
            mp2[nums2[i]]++;
        }  

        vector<int> res;

        // Iterate through one of the maps and find common elements
        for (auto& pair : mp1) 
        {
            int element = pair.first;
            if (mp2.find(element) != mp2.end()) 
            {
                res.push_back(element);
            }
        }

        return res;
    }
};