class Solution {
public:
    string minWindow(string s, string t)
{
    if( t == "")
    {
        return "";
    }

    unordered_map<char,int> mp;

    for(int i = 0; i < t.size(); i++)
    {
        mp[t[i]]++;
    }

    int need = mp.size();
    int have = 0;
    int l = 0, r =0;
    int minLen = INT_MAX;
    int min_pos = -1;
    string ans = "";

    unordered_map<char,int> window;

    while(r < s.size())
    {
        char c = s[r];
        window[c]++;

        if(mp.find(c) != mp.end() && window[c] == mp[c])
        {
            have++;
        }

        while(have == need)
        {
            if(r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                min_pos = l;
            }

            window[s[l]]--;

            if(mp.find(s[l]) != mp.end() && window[s[l]] < mp[s[l]])
            {
                have--;
            }
            l++;
        }

        r++;
    } 
    if( minLen < INT_MAX)
    {
        ans = s.substr(min_pos,minLen);
    }

    return ans;

}
};