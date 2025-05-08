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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int lvlsize = q.size();

            vector<int> lvl;

            for(int i = 0; i < lvlsize;i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                lvl.push_back(curr -> val);

                if(curr -> left) q.push(curr -> left);
                if(curr -> right) q.push(curr -> right);
            }

            res.push_back(lvl);
        }

        return res;
    }
};