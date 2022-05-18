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
    
    int idx;
    
    int search(vector<int>&inorder,int key,int start,int end){
        
        for(int i=start;i<=end;i++){
            if(key==inorder[i])
                return i;
        }
        
        return -1;
    }
    
    TreeNode* constructTree(vector<int>&inorder,vector<int>&postorder,int start,int end,int &idx){
        
        if(start>end)
            return NULL;
        
        TreeNode* root=new TreeNode(postorder[idx--]);
        
        if(start==end)
            return root;
        
        int pos=search(inorder,root->val,start,end);
        
       
        root->right=constructTree(inorder,postorder,pos+1,end,idx);
         root->left=constructTree(inorder,postorder,start,pos-1,idx);
        return root;
        
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int idx=postorder.size()-1;
        
        return constructTree(inorder,postorder,0,postorder.size()-1,idx);
    }
};
