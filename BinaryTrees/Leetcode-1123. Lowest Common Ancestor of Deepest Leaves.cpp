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
    
    int findDepth(TreeNode* root){
        if(root==NULL)
            return 0;
        return max(findDepth(root->left),findDepth(root->right))+1;
    }
                   
    TreeNode* helper(TreeNode* root,int maxDepth,int currDepth){
        if(root==NULL)
            return NULL;
        if(currDepth==maxDepth and root->left==NULL and root->right==NULL)
            return root;
        TreeNode* left=helper(root->left,maxDepth,currDepth+1);
        TreeNode* right=helper(root->right,maxDepth,currDepth+1);
        if(left and right)
            return root;
        else if(left)
            return left;
        return right;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL)
            return NULL;
        int maxDepth=findDepth(root);
        return helper(root,maxDepth,1);
    }
};
