class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int max_length = 0;         // To store the maximum length of substring
        int l = 0;               // Left pointer of the sliding window

        // Use an unordered_set to store characters of the current window
        std::unordered_set<char> char_set;

        // Iterate through the string with the right pointer
        for (int r = 0; r < s.size(); ++r) 
        {

            // Shrink the window if the current character is already in the set
            while (char_set.find(s[r]) != char_set.end()) {
                char_set.erase(s[l]); // Remove the leftmost character
                ++l;                  // Move the left pointer
            }

            // Add the current character to the set
            char_set.insert(s[r]);

            // Update the maximum length
            max_length = std::max(max_length, r - l + 1);
        }

        return max_length;
    }
};