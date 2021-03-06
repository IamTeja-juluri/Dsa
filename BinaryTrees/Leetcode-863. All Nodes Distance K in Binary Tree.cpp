//App 1 using level order
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
 
    unordered_map<TreeNode*,TreeNode* >mp;
  
    void mark(TreeNode* root){
        
        if(root==NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=1;i<=n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    mp[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    mp[curr->right]=curr;
                    q.push(curr->right);
                }
            }   
        }
        
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> res;
        if(root==NULL)
            return res;
        
        mark(root);
       
        unordered_map<TreeNode*,bool>visited;
   
        queue<TreeNode*> q;
        
        q.push(target);
        visited[target]=true;
        int level=0;
        
        while(!q.empty()){
            
            int n=q.size();
          
            if(level==k)
                break;
            
            for(int i=1;i<=n;i++){
                
                TreeNode* curr=q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                
                if(mp[curr] && !visited[mp[curr]]){
                    q.push(mp[curr]);
                    visited[mp[curr]]=true;
                }
                
            }
          level+=1;
        }

        
        while(!q.empty()){
           res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};

// app2 without level order
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
 
    unordered_map<TreeNode*,TreeNode* >mp;
     vector<int> res;
    unordered_map<TreeNode*,bool> visited;

  
    void mark(TreeNode* root){
        
        if(root==NULL)
            return;
        
        if(root->left){
            mp[root->left]=root;
            mark(root->left);
        }
        
        if(root->right){
            mp[root->right]=root;
            mark(root->right);
        }
        
        return;
    }
    
    void findNodes(TreeNode* root,int k){
        
        if(root==NULL)
            return;
        
        if(visited[root])
            return;
        
        if(k==0){
            res.push_back(root->val);
            return;
        }
        
        visited[root]=true;
        
        if(root->left)
            findNodes(root->left,k-1);
        
         if(root->right)
            findNodes(root->right,k-1);
        
         if(mp[root])
            findNodes(mp[root],k-1);
        
        return;
    }
    
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(root==NULL)
            return res;
        
        mark(root);
        findNodes(target,k);
        
        return res;
    }
};
