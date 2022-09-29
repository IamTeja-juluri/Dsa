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
    
    TreeNode* helper(TreeNode* root){
      
        if(root==NULL)
            return NULL;
        
        if(root->val==1 and root->left==NULL and root->right==NULL)
            return root;
        
        root->left= helper(root->left);
        root->right=helper(root->right);
        
        if(root->val==0 and root->left==NULL and root->right==NULL)
            return NULL;
        
        return root;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root==NULL)
            return NULL;
        
        return helper(root);
    }
};
