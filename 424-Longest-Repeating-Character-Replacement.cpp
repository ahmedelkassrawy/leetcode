class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        unordered_map<char,int> freq;

        int res = 0;
        int mxfreq = 0;
        int l = 0;

        for(int r = 0; r < s.size(); r++)
        {
            freq[s[r]]++;
            mxfreq = max(mxfreq,freq[s[r]]);
            
            while((r - l + 1) - mxfreq > k) 
            {
                freq[s[l]]--;
                l++;
            }
            res = max(res,r - l + 1);
        }

        return res;
    }
};