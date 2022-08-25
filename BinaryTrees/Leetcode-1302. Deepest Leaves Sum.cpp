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
    
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return max(lh,rh)+1;
    }
  
    int deepestLeavesSum(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int maxlevel=height(root);
        
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        int sum=0;
        
        while(!q.empty()){
            int n=q.size();
            for(int i=1;i<=n;i++){
                TreeNode* currNode=q.front();
                q.pop();
                if(level==maxlevel)
                    sum+=currNode->val;
                if(currNode->left)
                    q.push(currNode->left);
                if(currNode->right)
                    q.push(currNode->right);
            }
            level+=1;
        }
        
        return sum;
    }
};
