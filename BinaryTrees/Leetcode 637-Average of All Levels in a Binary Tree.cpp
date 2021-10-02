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
    void average(TreeNode* root,vector<double> &vec)
    {
        if(!root)
            return;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            double avg=0;
            for(int i=1;i<=n;i++)
            {
            TreeNode* curr=q.front();
                q.pop();
                avg+=curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            vec.push_back(avg/n);
        }
    }
   
    
    vector<double> averageOfLevels(TreeNode* root) {
      vector<double> v;
        average(root,v);
        return v;
    }
};
