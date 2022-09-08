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
    
    vector<int> arr;
    
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* helper(int l,int r){
        
        if(l>r)
            return NULL;
         
         if(l==r)
             return new TreeNode(arr[l]);
        
         int mid=(l+r)/2;
         
         TreeNode* newNode=new TreeNode(arr[mid]);
         newNode->left=helper(l,mid-1);
         newNode->right=helper(mid+1,r);
         return newNode;
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        
        if(root==NULL)
            return NULL;
        
        inorder(root);
        int n=arr.size();
        return helper(0,n-1);
    }
};
