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
    
    vector<TreeNode*> res;
    unordered_set<int> st;
    
    TreeNode* helper(TreeNode* root){
        
        if(root==NULL)
            return NULL;
       
        root->left=helper(root->left);
        root->right=helper(root->right);
        
        if(st.find(root->val)!=st.end()){
            if(root->left){
                res.push_back(root->left);
                root->left=NULL;
            }
            if(root->right){
                res.push_back(root->right);
                root->right=NULL;
            }
            return NULL;
        }
        
        return root;
    }
    
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        if(root==NULL)
            return res;
        
        for(auto x:to_delete)
            st.insert(x);
      
         TreeNode* node=helper(root);
        
         if(node)
             res.push_back(node);
      
        return res;
    }
};
