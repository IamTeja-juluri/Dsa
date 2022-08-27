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
    unordered_map<TreeNode*,TreeNode*> mp;
    
    void helper(TreeNode* root,TreeNode* par){
        if(root==NULL)
            return ;
        mp[root]=par;
        helper(root->left,root);
        helper(root->right,root);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
       
        if(root==NULL)
            return 0;
        
        helper(root,NULL);
        
        queue<TreeNode*> q;
        
        if(root->left)
            q.push({root->left});
        if(root->right)
            q.push({root->right});
        
        int sum=0;
        
        while(!q.empty()){
            
            TreeNode* currNode=q.front();
            q.pop();
           
            if(currNode->left){
                q.push(currNode->left);
                if(mp[currNode]->val % 2 == 0)
                    sum+=currNode->left->val;
            }
            
            if(currNode->right){
                q.push(currNode->right);
                if(mp[currNode]->val % 2 == 0)
                    sum+=currNode->right->val;
            }
           
        }
       
        return sum;
    }
};
