class Solution {
public:
    void leftView(TreeNode * root , vector<int > &v)
    {
        if(root==NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=1;i<=n;i++)
            {
                TreeNode * curr=q.front();
                q.pop();
                if(i==1)
                    v.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        
        
    }
     
    vector<int> leftSideView(TreeNode* root) {
        vector<int > res;
        leftView(root,res);
        return res;
            
    }
};
