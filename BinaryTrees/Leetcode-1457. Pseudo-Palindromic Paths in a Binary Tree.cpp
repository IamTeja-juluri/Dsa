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
    
    int count;
    vector<int> freq;
    
    Solution(){
        count=0;
        freq.resize(10,0);
    }
    
    void checkIfItsAPalindrome(){
        
        int oddcount=0;
        
        for(int i=1;i<=9;i++){
            if((freq[i]%2)==1)
                oddcount+=1;
        }
        
       if(oddcount<=1)
           count+=1;
        
    }
    
    void helper(TreeNode* root){
        
        if(root==NULL)
            return;
       
        freq[root->val]+=1;
        
        if(root->left==NULL and root->right==NULL){
            checkIfItsAPalindrome();
        }
        
        helper(root->left);
        helper(root->right);
        freq[root->val]-=1;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        helper(root);
        return count;
    }
};
