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
    void levelorder(TreeNode* root,vector<vector<int > > &res)
    {
        if(root==NULL)
            return ;
        stack<vector<int > > st;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int > v;
            int n=q.size();
            for(int i=1;i<=n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            st.push(v);
        }
        
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        
        
    }
    
    
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int > > res;
        levelorder(root,res);
        return res;
    }
};
