//app1 using set
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
    
    
    int ans=0;
    
    set<int> helper(TreeNode* root){
        
        set<int> st;
        
        if(root==NULL)
            return st;
        
        if(root->left==NULL and root->right==NULL){
            st.insert(root->val);
            return st;
        }
            
       set<int> s1=helper(root->left);
       set<int> s2=helper(root->right);
       
       s1.insert(s2.begin(),s2.end());
       
       auto its=s1.begin();
       auto ite=--(s1.end());
        
       int op1=abs(root->val-*its);
       int op2=abs(root->val-*ite);
       ans=max({ans,op1,op2}); 
       s1.insert(root->val);
        return s1;
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        if(root->left==NULL and root->right==NULL)
           return 0;
           
        set<int>s=helper(root);
           
        return ans;
    }
};
