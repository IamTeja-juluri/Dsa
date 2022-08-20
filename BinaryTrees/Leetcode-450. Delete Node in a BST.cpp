//app1
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
    
    int findPredecessor(TreeNode* root){
        root=root->left;
        while(root->right)
            root=root->right;
        return root->val;
    } 
    
    int findSuccessor(TreeNode* root){
        root=root->right;
        while(root->left)
            root=root->left;
        return root->val;
    }
 
    TreeNode* deleteNode(TreeNode* root, int key) {
        
      if(root==NULL)
          return NULL;
        
      if(root->val>key)
          root->left=deleteNode(root->left,key);
     else if(root->val<key)
          root->right=deleteNode(root->right,key);
     else{
         if(!root->left and !root->right)
            root=nullptr;
         else if(root->left){
             root->val=findPredecessor(root);
             root->left=deleteNode(root->left,root->val);
         }
         else{
              root->val=findSuccessor(root);
              root->right=deleteNode(root->right,root->val);
         }
     }   
        
        return root;
    }
};

//app2
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
    
    TreeNode* findMin(TreeNode* root){
        while(root->left)
            root=root->left;
        return root;
    }
    
 
    TreeNode* deleteNode(TreeNode* root, int key) {
        
      if(root==NULL)
          return NULL;
        
      if(root->val>key)
          root->left=deleteNode(root->left,key);
     else if(root->val<key)
          root->right=deleteNode(root->right,key);
     else{
         if(!root->left and !root->right){
           delete root;
           root=NULL;  
         }
         else if(root->left==NULL){
             TreeNode* curr=root;
             root=root->right;
             delete curr;
         }
         else if(root->right==NULL){
             TreeNode* curr=root;
             root=root->left;
             delete curr;
         }
         else{
             TreeNode* curr=findMin(root->right);
             root->val=curr->val;
             root->right=deleteNode(root->right,curr->val);
             
         }
     }   
        
        return root;
    }
};
