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

//   unordered_map<int,vector<int> > mp;
    
//     vector<TreeNode*> ans;
  
//     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
           
//          if(root->left==NULL and root->right==NULL){
//             vector<TreeNode*>v;
//             v.push_back(root);
//             if(mp.find(root->val)!=mp.end() and mp[root->val]==v)
//                 ans.push_back(root);
//             else
//                 mp[root->val]=v;
//             return v;
//         }
        
//         vector<TreeNode*> left=findDuplicateSubtrees(root->left);
//         vector<TreeNode*> right=findDuplicateSubtrees(root->right);
        
//         left.push_back(root);
        
//         for(TreeNode* x:right)
//             left.push_back(x);
        
//         if(mp.find(root->val)!=mp.end() and mp[root->val]==left)
//             ans.push_back(root);
//         else
//             mp[root->val]=left;
        
//         return left;

class Solution {
public:
    
    unordered_map<string,int> mp;
    vector<TreeNode*> ans;
    
    string helper(TreeNode* root){
        
        if(root==NULL)
            return "";
        
      string left=helper(root->left);
      string right=helper(root->right);
      
      string s=to_string(root->val)+"$"+left+"$"+right+"$";
      
        if(mp[s]==1)
            ans.push_back(root);
        mp[s]++;
        
        return s;
    }
    
     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    
       if(root==NULL)
           return ans;
      
         helper(root);
        
         return ans;
    }
};
