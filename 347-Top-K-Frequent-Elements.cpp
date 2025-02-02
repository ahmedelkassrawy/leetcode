class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> cnt;
        for(int i = 0; i < nums.size();i++)
        {
            cnt[nums[i]]++;
        }

        // Step 2: Create a vector of vectors to store numbers with the same frequency
        // The index represents the frequency, and the value is a vector of numbers with that frequency
        vector<vector<int>> freq(nums.size() + 1);
        for (const auto& pair : cnt)
        {
            int num = pair.first;
            int frequency = pair.second;
            freq[frequency].push_back(num);
        }

        // Step 3: Iterate from the highest frequency to the lowest and collect the top k elements
        vector<int> res;
        for (int i = freq.size() - 1; i >= 0; i--)
        {
            for (int num : freq[i])
            {
                res.push_back(num);
                if (res.size() == k)
                {
                    return res;
                }
            }
        }

        return res;
    }
};

// //vector<int> nums = {4, 4, 4, 5, 5, 6, 6, 6, 6};
// int k = 2;

// {
//     4: 3,
//     5: 2,
//     6: 4
// }

// [
//     [],       // Frequency 0
//     [],       // Frequency 1
//     [5],      // Frequency 2
//     [4],      // Frequency 3
//     [6],      // Frequency 4
//     [],       // Frequency 5
//     [],       // Frequency 6
//     [],       // Frequency 7
//     [],       // Frequency 8
//     []        // Frequency 9
// ]