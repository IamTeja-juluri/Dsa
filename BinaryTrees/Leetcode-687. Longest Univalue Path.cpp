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
    int dfs(TreeNode* root,int val)
    {
        if(root==NULL)
            return 0;
        if(root->val != val)
            return 0;
        return 1 + max(dfs(root->left,val),dfs(root->right,val));
    }
    int  helper(TreeNode* root)
    {
        if(root==NULL) 
            return 0;
       
        int cnt = dfs(root->left,root->val) + dfs(root->right,root->val);
        
        return max({cnt,helper(root->left),helper(root->right)});
        
    }
    int longestUnivaluePath(TreeNode* root) {
        return helper(root);
    }
};
