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
    int traverse(TreeNode* root) 
    {
        if(root == nullptr) return 0;

        int l = traverse(root -> left);
        if(l == -1) return -1;

        int r = traverse(root -> right);
        if(r == -1) return -1;

        if(abs(r - l) > 1) return -1;
        return 1 + max(r,l);
    }

    bool isBalanced(TreeNode* root) 
    {
        return traverse(root) != -1;
    }
};