class Solution {
public:
    unordered_map<TreeNode*, int> memo;

    int rob(TreeNode* root) {
        if (!root) return 0;
        if (memo.count(root)) return memo[root];

        int robThis = root->val;
        
        if (root->left) {
            robThis += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            robThis += rob(root->right->left) + rob(root->right->right);
        }

        int skipThis = rob(root->left) + rob(root->right);

        return memo[root] = max(robThis, skipThis);
    }
};
