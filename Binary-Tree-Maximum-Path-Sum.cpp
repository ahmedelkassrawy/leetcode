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
class Solution 
{
public:
    int maxPathSum(TreeNode* root) 
    {
        int mx = INT_MIN;
        dfs(root,mx);

        return mx;
    }

    int dfs(TreeNode* root,int& mx)
    {
        if(!root) return 0;

        int l = max(dfs(root -> left,mx),0);
        int r = max(dfs(root -> right,mx),0);

        int curr = root -> val + l + r;

        mx = max(mx,curr);

        return root -> val + max(l,r);
    }
};