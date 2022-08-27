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
    
    
    bool isEvenOddTree(TreeNode* root) {
        
        if(root==NULL)
            return true;
        
        queue<TreeNode*> q;
          
        int level=0;
        
        if(((root->val)%2)!=1)
            return false;
        
        q.push(root);
        
        bool odd=false,even=false;
    
        while(!q.empty()){
            
            int n=q.size();
            
            if(level%2==0){
                odd=true;
                even=false;
            }
            else{
                even=true;
                odd=false;
            }
            
            int prevMin=INT_MIN;
            int prevMax=INT_MAX;
            
            for(int i=1;i<=n;i++){
            
            TreeNode* currNode=q.front();
            q.pop();
                
            if(odd==true){
                if(currNode->val%2==1 and currNode->val>prevMin)
                    prevMin=currNode->val;
                else 
                    return false;
            }
                
            if(even==true){
                if(currNode->val%2==0 and currNode->val<prevMax)
                    prevMax=currNode->val;
                else 
                    return false;
            }
           
                
            if(currNode->left)
                q.push(currNode->left);
            
            if(currNode->right)
                q.push(currNode->right);
                
            }
            level+=1;

        }
        
        return true;
      
    }
};
