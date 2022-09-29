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
    
    int first_min=INT_MAX;
    int second_min=INT_MAX;
    bool found=false;
    
    void helper(TreeNode* root){
        if(root==NULL)
            return;
        if(root->val==INT_MAX)
            found=true;
        if(root->val<first_min){
            second_min=first_min;
            first_min=root->val;
        }
        else if(root->val>first_min and root->val<second_min)
            second_min=root->val;
        helper(root->left);
        helper(root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        first_min=root->val;
        helper(root);
        if(first_min==INT_MAX)
            return -1;
        if(second_min==INT_MAX and found==false)
            return -1;
        return second_min;
    }
};
