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
    
    void pathSum(TreeNode* root,vector<vector<int> > &res,vector<int> &v,int targetSum){
        
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            
             v.push_back(root->val);
            if(targetSum-root->val==0){
                res.push_back(v);
            }
            v.pop_back();
            return;
        }
        
        v.push_back(root->val);
        pathSum(root->left,res,v,targetSum-root->val);
        pathSum(root->right,res,v,targetSum-root->val); 
        v.pop_back();
        return;
        
    }
     
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int> > res;
        vector<int> v;
         
        pathSum(root,res,v,targetSum);
        
        return res;
        
    }
};