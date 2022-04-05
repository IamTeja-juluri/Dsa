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
    
    int ans=INT_MIN;
    
    int findMaxSum(TreeNode* root){
        
        if(root==NULL)
            return 0;
        
        if(root->left==NULL && root->right==NULL){
            ans=max(ans,root->val);
            return root->val;
        }
        
        int l=findMaxSum(root->left);
        int r=findMaxSum(root->right);
        
        ans=max({ans,root->val+l+r,root->val+l,root->val+r,root->val});
        
        return max({root->val+l,root->val+r,root->val});
    }
    
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int res=findMaxSum(root);
        
        return ans;
    }
};
