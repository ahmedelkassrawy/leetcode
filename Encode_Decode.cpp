class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string encoded;
        for (const string& s : strs) 
        {
            int len = s.size();
            encoded += to_string(len) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) 
    {
        vector<string> decoded;
        int i = 0;
        while (i < s.size()) 
        {
            // Find the position of the delimiter '#'
            int delimiterPos = s.find('#', i);
            // Extract the length of the string
            int len = stoi(s.substr(i, delimiterPos - i));
            // Move the index to the start of the actual string
            i = delimiterPos + 1;
            // Extract the string
            string str = s.substr(i, len);
            decoded.push_back(str);
            // Move the index to the next length
            i += len;
        }
        return decoded;
    }
};


/*
### Example Walkthrough:
Input: {"hello", "world", "leet", "code"}

Step 1: Encoding
---------------------------
"hello" -> "5#hello"
"world" -> "5#world"
"leet"  -> "4#leet"
"code"  -> "4#code"

Final Encoded String: "5#hello5#world4#leet4#code"

Step 2: Decoding
---------------------------
Read "5", extract "hello"
Read "5", extract "world"
Read "4", extract "leet"
Read "4", extract "code"

Final Decoded List: {"hello", "world", "leet", "code"}

### Complexity:
- **Time Complexity:** O(N) for both encoding and decoding
- **Space Complexity:** O(N)
*/
