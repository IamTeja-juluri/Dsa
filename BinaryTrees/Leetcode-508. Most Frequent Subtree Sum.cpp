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
    vector<int>res;
    unordered_map<int,int>mp;
    
    int findSubtreeSums(TreeNode* root){
        
        if(root==NULL)
            return 0;
        
        int l=findSubtreeSums(root->left);
        int r=findSubtreeSums(root->right);
        
        int data=root->val+l+r;
        
        mp[data]++;
        
        return data;
    }
    
     
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        int ans=findSubtreeSums(root);
        
        int maxi=0;
        
        for(auto it:mp)
            maxi=max(maxi,it.second);
        
        for(auto it:mp){
            if(maxi==it.second)
                res.push_back(it.first);
        }
        
        return res;
    }
};
