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
    
    int ans=0;
    
    void helper(TreeNode* root,int curr,int mask){
        
        if(root==NULL)
            return ;
        
        ans=max(ans,curr); //see test case 1
        
        if(mask==0){
           helper(root->left,curr+1,1);
           helper(root->right,1,0); 
        }
        else{
        helper(root->right,curr+1,0);
        helper(root->left,1,1);
        }
    }
    
    int longestZigZag(TreeNode* root) {
    
      helper(root->left,1,1);
      helper(root->right,1,0); 
      return ans;   
    }
};
