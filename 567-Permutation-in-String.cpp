class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Count(26, 0), s2Count(26, 0);
        int n = s1.size(), m = s2.size();

        // Count frequency of characters in s1
        for (char c : s1) s1Count[c - 'a']++;

        // Initial window of size s1.size() in s2
        for (int r = 0; r < n; r++) s2Count[s2[r] - 'a']++;

        if (s1Count == s2Count) return true;

        // Sliding window
        int l = 0;
        for (int r = s1.size(); r < s2.size(); r++) 
        {
            s2Count[s2[r] - 'a']++;    // Add new character in the window
            s2Count[s2[l] - 'a']--;    // Remove old character from the window

            if (s1Count == s2Count) return true;

            l++;
        }

        return false;
    }
};
