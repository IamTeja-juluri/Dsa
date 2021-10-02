//Approach 1
class Solution {
public:
    void traversal(TreeNode* root,stack<TreeNode*> &st){
        
        if(root==NULL)
            return;
        
        traversal(root->right,st);
        traversal(root->left,st);
        st.push(root);
        return;
        
    }
    void flatten(TreeNode* root) {
        
        if(root==NULL)
            return ;
        
        stack<TreeNode*> st;
        
        traversal(root,st);
        
        TreeNode*curr=root;
        
        st.pop();
        
        while(!st.empty()){
            
            curr->left=NULL;
            TreeNode* temp=st.top();
            curr->right=temp;
            curr=curr->right;
            st.pop();
            
        }
        curr->left=NULL;
        curr->right=NULL;
        
        
    }
};


//Approach 2

class Solution {
public:
    
    void flatten(TreeNode* root) {
        
        if(root==NULL)
            return ;
        
        stack<TreeNode*> st;
        
        st.push(root);
        
        while(!st.empty()){
            
            TreeNode* curr=st.top();
            st.pop();
            
            if(curr->right!=NULL)
                st.push(curr->right);
            if(curr->left!=NULL)
                st.push(curr->left);
            
            if(!st.empty())
            curr->right=st.top();
            
            curr->left=NULL;
            
        }
        
    }
};
