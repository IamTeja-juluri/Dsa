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
    
    vector<string> res;

    void TreePaths(TreeNode* root,string s){
        
        string x=to_string(root->val);
        
        if(root->left==NULL && root->right==NULL){
            res.push_back(s+x);
            return;
        }
        
        
        if(root->left!=NULL) 
            TreePaths(root->left,s+x+"->");
        if(root->right!=NULL) 
            TreePaths(root->right,s+x+"->");
        
    
        return;
        
    }
    
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
    
        
        if(root==NULL){
            return res;
        }
        
        string s="";
        
        TreePaths(root,s);
        
        return res;
        
    }
};
