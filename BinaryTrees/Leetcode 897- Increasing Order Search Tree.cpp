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

// approach 1 is to store inorder traversal in queue and then make changes to tree
// approach 2 is the below one
class Solution {
public:

    pair<TreeNode*,TreeNode*> formatTree(TreeNode* root){

        if(root == NULL)
            return {NULL,NULL};

        if(root->left == NULL && root->right == NULL)
            return {root,root};
        
        pair<TreeNode*,TreeNode*> leftNode = formatTree(root->left);

        if(root)
            root->left=NULL;

        if(leftNode.second!=NULL)
            leftNode.second->right = root;

        pair<TreeNode*,TreeNode*> rightNode = formatTree(root->right);

        if(root!=NULL)
            root->right=rightNode.first;

        return {leftNode.first != NULL ? leftNode.first : root,rightNode.second != NULL ? rightNode.second : root};
    }


    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL)
            return NULL;

        pair<TreeNode*,TreeNode*> ans = formatTree(root);
        return ans.first; 
    }

};
