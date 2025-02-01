class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto s: strs)
        {
            string word = s;
            sort(word.begin(), word.end());
            mp[word].push_back(s);
        }
        
        vector<vector<string>> ans;

        for(auto x: mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};