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
    

    int minDepth(TreeNode* root) {
        
        if(root){
        
        if(root->left==NULL && root->right==NULL)
            return 1;
        
        int lh=INT_MAX;
        int rh=INT_MAX;
            
        if(root->left)    
        lh=minDepth(root->left);
            
        if(root->right)
        rh=minDepth(root->right);
        
        return 1+min(lh,rh);
            
            
        }
        
        return 0;
        
    }
};
