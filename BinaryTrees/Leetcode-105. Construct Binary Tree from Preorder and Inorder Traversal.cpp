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
    
    
    int search(vector<int>&inorder,int key,int start,int end){
        
        for(int i=start;i<=end;i++){
            if(key==inorder[i])
                return i;
        }
        return -1;
    }
    
    TreeNode* constructTree(vector<int>&preorder,vector<int>&inorder,int start,int end,int &idx){
        
        if(start>end)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[idx++]);
        
        if(start==end)
            return root;
        
        int pos=search(inorder,root->val,start,end);
        root->left=constructTree(preorder,inorder,start,pos-1,idx);
        root->right=constructTree(preorder,inorder,pos+1,end,idx);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return constructTree(preorder,inorder,0,preorder.size()-1,idx);
        
    }
};
