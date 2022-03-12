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
    
    unordered_map<int,int> mp;
    
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        mp[root->val]+=1;
        inorder(root->right);
    }
    
    
    vector<int> findMode(TreeNode* root) {
        
        vector<int> mode;
        inorder(root);
        int ans=0;
        
        for(auto x:mp)
            ans=max(ans,x.second);
        
        for(auto x:mp){
            if(x.second==ans)
                mode.push_back(x.first);
        }
        
        return mode;
     
    }
};
