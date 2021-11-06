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
    bool isCousins(TreeNode* root, int x, int y) {
      
        if(root==NULL)
            return false;
        
        
        queue< pair<TreeNode*,TreeNode*> > q;
        TreeNode* parx=NULL;
        TreeNode* pary=NULL;
        
        q.push({root,new TreeNode(-1)});
        
        while(!q.empty()){
            
            int n=q.size();
            pair<TreeNode*,TreeNode*> p;
            
            while(n--){
                
                p=q.front();
                 q.pop();
                
                if(p.first->val==x){
                    parx=p.second;
                }
                
                if(p.first->val==y){
                    pary=p.second;
                }
                
              
                if(p.first->left){
                    q.push({p.first->left,p.first});
                }
                
                if(p.first->right){
                    q.push({p.first->right,p.first});
                }
                
                
            }
            
            if(parx && pary)
                return parx!=pary;
            
            if( (parx && !pary) || (!parx && pary) )
                return false;
              
        }
        
        return false;
    }
};
