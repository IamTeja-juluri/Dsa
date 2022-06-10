//app1 -basic dfs
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
    
    long long findPath(TreeNode* root,long long targetSum){
        
        if(root==NULL)
            return 0;
        
        long long ans=0;
        
        if(targetSum==root->val)
         ans=1;
        
        return ans+findPath(root->left,targetSum-root->val)+findPath(root->right,targetSum-root->val);
    }
 
    
    int pathSum(TreeNode* root, int targetSum) {
        
       if(root==NULL)
            return 0;
       
       return findPath(root,targetSum)+ pathSum(root->left,targetSum)+ pathSum(root->right,targetSum);  
    }
};
