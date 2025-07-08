class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.empty()) return nullptr;

        int root_val = preorder[0];
        TreeNode* root = new TreeNode(root_val);

        // Fixed line: find root_val index in inorder
        int idx = find(inorder.begin(), inorder.end(), root_val) - inorder.begin();

        vector<int> leftpre(preorder.begin() + 1, preorder.begin() + 1 + idx);
        vector<int> leftin(inorder.begin(), inorder.begin() + idx);
        vector<int> rightpre(preorder.begin() + 1 + idx, preorder.end());
        vector<int> rightin(inorder.begin() + idx + 1, inorder.end());

        root->left = buildTree(leftpre, leftin);
        root->right = buildTree(rightpre, rightin);

        return root;
    }
};
