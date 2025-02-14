class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> st;

        int l = 0;
        int mx_len = 0;

        for(int r = 0; r < s.size(); r++)
        {
            while(st.find(s[r]) != st.end()) //repeated string
            {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);

            mx_len = max(mx_len , r - l + 1);
        }

        return mx_len;
    }
};