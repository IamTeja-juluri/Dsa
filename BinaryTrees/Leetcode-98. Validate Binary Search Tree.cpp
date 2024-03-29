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
    
    bool helper(TreeNode* root,long min_val,long max_val){
     if(root==NULL)
			return true;
        
    return root->val>min_val and root->val<max_val and helper(root->left,min_val,root->val) and helper(root->right,root->val,max_val);       
   }
    
    bool isValidBST(TreeNode* root) {
     
       return helper(root,LONG_MIN,LONG_MAX);
        
    }
};
