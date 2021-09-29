class Solution {
public:
  
    void levelorder(vector<vector<int>> &res,TreeNode* root)
    {
      
        if(root==NULL)
            return;
      
        queue<TreeNode* > q;
        q.push(root);
      
        while(!q.empty())
        {
            int n=q.size();
            vector<int > v;
          
            for(int i=1;i<=n;i++ )
             {
              
            TreeNode* curr=q.front();
                q.pop();
            v.push_back(curr->val); 
              
            if(curr->left)
                q.push(curr->left);
              
            if(curr->right)
                q.push(curr->right);
            }
          
                res.push_back(v);
          
        }
        
    }
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int > > res;
        levelorder(res,root);
        return res;
      
    }
};
