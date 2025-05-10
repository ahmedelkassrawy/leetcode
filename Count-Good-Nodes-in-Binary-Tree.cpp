/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) 
    {
        return dfs(root, root -> val);
    }

    int dfs(TreeNode* root,int curr_mx)
    {
        if(!root) return 0;

        int good = 0;
        if(root -> val >= curr_mx) good = 1;

        curr_mx = max(curr_mx,root -> val);

        good += dfs(root -> right,curr_mx);
        good += dfs(root -> left,curr_mx);

        return good;
    }
};