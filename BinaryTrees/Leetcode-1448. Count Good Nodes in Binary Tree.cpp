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
    
    int cnt;
    
    void countNodes(TreeNode* root,int minval){
        
        if(root==NULL)
            return ;
        
        minval=max(minval,root->val);
        
        if(minval<=root->val)
            cnt+=1;
        
        countNodes(root->left,minval);        
        countNodes(root->right,minval);        
    }
    
    
    
    
    int goodNodes(TreeNode* root) {
      
      if(root==NULL)
          return 0;
      cnt=0;
      countNodes(root,INT_MIN);  
      return cnt;   
    }
};
