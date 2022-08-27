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
    
    unordered_map<TreeNode*,TreeNode*> mp;
    unordered_set<TreeNode*> st;
    
    void helper(TreeNode* root,TreeNode* par){
        if(root==NULL)
            return ;
        mp[root]=par;
        helper(root->left,root);
        helper(root->right,root);
    }
    
    TreeNode* findStart(TreeNode* root,int start){
        
        if(root==NULL)
            return NULL;
        
        if(root->val==start)
            return root;
        
        TreeNode* left=findStart(root->left,start);
        TreeNode* right=findStart(root->right,start);
        
        if(left)
            return left;
        
        if(right)
            return right;
        
        return NULL;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        
        if(root==NULL)
            return NULL;
        
        helper(root,NULL);
        TreeNode* startNode=findStart(root,start);
        queue<TreeNode*> q;
        q.push(startNode);
        st.insert(startNode);
        int level=0;
        
        while(!q.empty()){
            
        int n=q.size();
            
        for(int i=1;i<=n;i++){
                
            TreeNode* currNode=q.front();
            q.pop();
            
            if(mp[currNode] and st.find(mp[currNode])==st.end()){
                q.push(mp[currNode]);
                st.insert(mp[currNode]);
            }
            
            if(currNode->left and st.find(currNode->left)==st.end()){
                q.push(currNode->left);
                st.insert(currNode->left);
            }
            
            if(currNode->right and st.find(currNode->right)==st.end()){
                q.push(currNode->right);
                st.insert(currNode->right);
            }
            
        }
            
            level+=1;
    }
        
   
        return level-1;
    }
};
