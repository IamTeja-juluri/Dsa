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
    int count;
    
    Solution(){
        count=0;
    }
    
    pair<int,int> helper(TreeNode* root){
        
        if(root==NULL)
            return {0,0};
        
        if(root->left==NULL and root->right==NULL){
            count+=1;
            return {root->val,1};
        }
        
        pair<int,int> left=helper(root->left);
        pair<int,int> right=helper(root->right);
        
        int curr_count=left.second+right.second+1;
        int value=left.first+right.first+root->val;
        
        if((value/curr_count)==root->val)
            count+=1;
        
        return {value,curr_count};
        
    }
    
    int averageOfSubtree(TreeNode* root) {
        
         if(root==NULL)
            return 0;
        
        helper(root);
        return count;
        
    }
};
