//tree dp
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
    
    unordered_map<TreeNode*,int> memo;
    int findMaxSum(TreeNode* root){
        
        if(root==NULL)
            return 0;
        
        if(memo.find(root)!=memo.end())
            return memo[root];
        
       int incl=root->val;
       int op1=0;
       if(root->left)
           incl+=findMaxSum(root->left->left)+findMaxSum(root->left->right);
         if(root->right)
           incl+=findMaxSum(root->right->left)+findMaxSum(root->right->right);
       
        int excl=findMaxSum(root->left)+findMaxSum(root->right);
        return memo[root]=max(incl,excl);
        
    }
    
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        return findMaxSum(root);
    }
};
