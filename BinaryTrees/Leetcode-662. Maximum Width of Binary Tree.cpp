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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;        
        q.push({root, 0});
        
        long res = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            long first=q.front().second;
            long last=q.back().second;
            
            res = max(res, last - first + 1);
            
            for(int i = 1; i <=size; i++){
                long idx = q.front().second;
                TreeNode* node = q.front().first;
                q.pop();
                if(node->left)
                    q.push({node->left, idx*2+1});
                if(node->right)
                    q.push({node->right, idx*2+2});
            }
            
        }
        
        return res;
    }
};
     
