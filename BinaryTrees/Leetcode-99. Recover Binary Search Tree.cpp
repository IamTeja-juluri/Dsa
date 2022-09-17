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

// approach 1 is to do inorder
// and sort inorder traversal as elements wont be in sorted order since two nodes are swapped
// again do inorder traversal and maintain a pointer to every element in stored inorder res and check
// if curr inorder node val is equal to the pointer pointing to a value in array
// this is brute force way
// watch strivers video for quick revision
// approach 2 is optimal

class Solution {
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
public:
    
    void helper(TreeNode* root){
        
        if(root==NULL)
            return;
        
        helper(root->left);
        
        if(root->val<prev->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else
                last=root;
        }
        
        prev=root;
        helper(root->right);
        
    }
    
    void recoverTree(TreeNode* root) {
        
        prev=new TreeNode(INT_MIN);
      
        first=NULL;
        middle=NULL;
        last=NULL;
        
        helper(root);
      
        if(first and last)
            swap(first->val,last->val);
        
        else if(first and middle)
            swap(first->val,middle->val);
        
    }
};
