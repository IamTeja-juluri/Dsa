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
    int sum;
    
    void addup(TreeNode* root,int ans){
        
        if(root==NULL)
            return;
        
        if(root->left==NULL && root->right==NULL){
            sum=sum+ans*10+root->val;
            return;
        }
        
        addup(root->left,(ans*10)+root->val);
        addup(root->right,(ans*10)+root->val);
        
        
    }
    
    
    int sumNumbers(TreeNode* root) {
        
        sum=0;
        addup(root,0);
        return sum;
    }
};
