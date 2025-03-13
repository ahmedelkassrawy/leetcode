class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string>res;
        unordered_map<char, string> digit = {
            {'2', \abc\},
            {'3', \def\},
            {'4', \ghi\},
            {'5', \jkl\},
            {'6', \mno\},
            {'7', \pqrs\},
            {'8', \tuv\},
            {'9', \wxyz\}
        };
        if(digits.empty()) return res;
        backtrack(res,\\,digits,digit,0);
        return res;
    }

private:
    void backtrack(vector<string> &res,string s,string digits,unordered_map<char, string>&digit,int idx)
    {
        if(idx == digits.length())
        {
            res.push_back(s);
            return;
        }

        string letters = digit.at(digits[idx]);
        for(char c : letters)
        {
            backtrack(res,s + c,digits,digit,idx + 1);
        }
    }
};