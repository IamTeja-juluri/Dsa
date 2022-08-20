/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
  
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {

       if(root==NULL)
       return NULL;

       TreeNode* predecessor=NULL;

       while(root!=NULL){
         if(root->val>=p->val)
            root=root->left;
        else{
            predecessor=root;
            root=root->right;
         }
       }

       return predecessor;
    }
};
