class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subst;
        backtrack(candidates, target, 0, subst, 0, res);
        return res;        
    }

private:
    void backtrack(std::vector<int>& candidates, int target, int idx, vector<int>& subst, int total, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(subst);
            return;
        }

        if (total > target || idx >= candidates.size()) return;

        //include
        subst.push_back(candidates[idx]);
        backtrack(candidates, target, idx, subst, total + candidates[idx], res);
        //we use the idx without idx + 1 , because here we could reuse the same idx again if we have to

        //exclude
        subst.pop_back();
        backtrack(candidates, target, idx + 1, subst, total, res);
        //here we are excluding so the idx + 1 is a must and total + 0 since we are excluding the curr element, no gain
    }    
};
