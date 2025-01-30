class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return \\; // Handle empty string case

        string res = \\;
        int reslen = 0;

        for (int i = 0; i < s.size(); i++) 
        {
            // Odd-length palindromes
            int l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > reslen) {
                    res = s.substr(l, r - l + 1); // Correct substring extraction
                    reslen = r - l + 1;
                }
                l--;
                r++;
            }

            // Even-length palindromes
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) 
            {
                if (r - l + 1 > reslen) 
                {
                    res = s.substr(l, r - l + 1); // Correct substring extraction
                    reslen = r - l + 1;
                }

                l--;
                r++;
            }
        }

        return res;
    }
};