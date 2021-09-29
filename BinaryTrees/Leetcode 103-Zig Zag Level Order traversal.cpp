class Solution {
public:

    void zigzag(vector<vector<int >> &res,TreeNode* root)
    {
        
        if(root==NULL)
            return;
            
        deque<TreeNode*> dq;
        dq.push_back(root);
        int j=0;
        
        while(!dq.empty())
        {
            j+=1;
            int n=dq.size();
            vector<int> v;
            for(int i=1;i<=n;i++)
        {
            if(j%2==0)
            {
                TreeNode*curr=dq.back();
               dq.pop_back();
               v.push_back(curr->val);
              
               if(curr->right)
               dq.push_front(curr->right);
               
                if(curr->left)
               dq.push_front(curr->left);
               
            }
            if(j%2==1)
            {
               TreeNode*curr=dq.front();
               dq.pop_front();
               v.push_back(curr->val);
               
               if(curr->left)
               dq.push_back(curr->left);
               
               if(curr->right)
               dq.push_back(curr->right);
               
            }
        }
            res.push_back(v);
        }
    }
    
   

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >res;
        zigzag(res,root);
        return res;
    }
};
