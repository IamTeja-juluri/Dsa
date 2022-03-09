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
    
    vector<int> v;
    
    void findout(TreeNode* root){
        
        if(root==NULL) 
            return ;
        
        findout(root->left);
        v.push_back(root->val);
        findout(root->right);
        
        return;
    } 
    
    int getMinimumDifference(TreeNode* root) {
       
        if(root==NULL) 
            return 0;
        
        findout(root);
        
        
        int mindiff=INT_MAX;
        
        for(int i=0;i<v.size()-1;i++){
            mindiff=min(mindiff,v[i+1]-v[i]);
        }
        
        return mindiff;
    }
};
