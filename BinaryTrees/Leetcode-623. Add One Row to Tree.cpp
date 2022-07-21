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
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
       
        if(d==1){
            TreeNode* newNode=new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level=1;
        
        while(!q.empty()){
            
            
            int n=q.size();
            
            for(int i=1;i<=n;i++){
                
                TreeNode* currNode=q.front();
                q.pop();
                
                if(level==d-1){
                    
                    TreeNode* leftNode=new TreeNode(val);
                    TreeNode* rightNode=new TreeNode(val);
                    
                    leftNode->left=currNode->left;
                    rightNode->right=currNode->right;
                    
                    currNode->left=leftNode;
                    currNode->right=rightNode;
                }
                else{
                if(currNode->left)
                    q.push(currNode->left);
                if(currNode->right)
                    q.push(currNode->right);
                }
            }
            
            level+=1;
            if(level==d)
                break;
        }
        
        return root;
       
    }
};
