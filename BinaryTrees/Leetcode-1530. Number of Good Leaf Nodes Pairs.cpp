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
    
    int cnt=0;
    
    vector<int>helper(TreeNode* root,int dist){
        
        if(root==NULL)
            return{0};
        
        if(root->left==NULL and root->right==NULL)
            return {1};
        
        vector<int> left=helper(root->left,dist);
        vector<int> right=helper(root->right,dist);
        
        for(auto x:left){
            for(auto y:right){
                if(x>0 and y>0 and x+y<=dist)
                    cnt+=1;
            }
        }
        
        vector<int> ans;
        
        for(auto x:left){
            if(x>0 and x+1<=dist)
                ans.push_back(x+1);
        }
        
         for(auto x:right){
            if(x>0 and x+1<=dist)
                ans.push_back(x+1);
        }
            
       return ans;
    }

    int countPairs(TreeNode* root, int distance) {
        
        if(root==NULL)
            return 0;
        helper(root,distance);
        return cnt;
    }
};
