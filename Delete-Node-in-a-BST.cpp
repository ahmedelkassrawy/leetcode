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
    TreeNode* findmin(TreeNode* node)
    {
        while(node -> left)
        {
            node = node -> left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return nullptr;

       if(root -> val != key && root -> val < key)
       {
            root -> right =  deleteNode(root -> right,key);
       }
       else if(root -> val != key && root -> val > key)
       {
            root -> left =  deleteNode(root -> left,key);
       }
       else
       {
            if(!root -> left) //replace with the right child
            {
                TreeNode* right_child = root -> right;
                delete root;
                return right_child;
            }
            else if(!root -> right) //replace with the left child
            {
                TreeNode* left_child = root -> left;
                delete root;
                return left_child;
            }
            else
            {
                //has two childs find the inorder successor
                TreeNode* succ = findmin(root -> right);
                root -> val = succ -> val;
                root -> right = deleteNode(root -> right , succ -> val);
            }
       }

       return root;
    }
};