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
    
   
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if(n==1){
            vector<TreeNode*> temp;
            TreeNode* node=new TreeNode(0);
            temp.push_back(node);
            return temp;
        }
        
        vector<TreeNode*> ans;
        
        for(int i=1;i<n;i+=2){
           vector<TreeNode*> left=allPossibleFBT(i);
           vector<TreeNode*> right=allPossibleFBT(n-i-1);
           for(TreeNode* x:left){
               for(TreeNode* y:right){
                   TreeNode*  root=new TreeNode(0);
                   root->left=x;
                   root->right=y;
                   ans.push_back(root);
              }
           } 
        }
        
        return ans;
    }
    
};
