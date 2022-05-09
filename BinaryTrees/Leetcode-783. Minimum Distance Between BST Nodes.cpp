//another soln is by using inorder traversal and take min of adjacent elements
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
    
    int ans=INT_MAX;
    TreeNode* curr=NULL;

    void findmin(TreeNode* root){
        
        if(root==NULL)
            return;
        
        if(root->left)
            findmin(root->left);
        
        if(curr)
            ans=min(ans,abs(root->val-curr->val));
        curr=root;
        
        if(root->right)
            findmin(root->right);
        
       
    }
    
    int minDiffInBST(TreeNode* root) {
      
      if(root==NULL)
          return 0;
       
    
        findmin(root);
       
        return ans;
    }
};
