/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    
    vector<vector<int>> verticalOrder(TreeNode *root) {
        
      vector<vector<int> > ans;
      if(root==NULL)
      return ans;
      map<int,vector<int> > mp;

      queue<pair<TreeNode*,int> > q;
      q.push({root,0});
      mp[0].push_back(root->val);

      while(!q.empty()){
          int val=q.front().second;
          TreeNode* currNode=q.front().first;
          q.pop();
          if(currNode->left){
              q.push({currNode->left,val-1});
              mp[val-1].push_back(currNode->left->val);
          }
          if(currNode->right){
              q.push({currNode->right,val+1});
              mp[val+1].push_back(currNode->right->val);
          }
      } 
      
      for(auto x:mp)
          ans.push_back(x.second);

      return ans;
    }
};
