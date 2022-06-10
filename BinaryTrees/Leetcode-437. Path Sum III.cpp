//app1 -basic dfs
class Solution {
public:
    
    long long findPath(TreeNode* root,long long targetSum){
        
        if(root==NULL)
            return 0;
        
        long long ans=0;
        
        if(targetSum==root->val)
         ans=1;
        
        return ans+findPath(root->left,targetSum-root->val)+findPath(root->right,targetSum-root->val);
    }
 
    
    int pathSum(TreeNode* root, int targetSum) {
        
       if(root==NULL)
            return 0;
       
       return findPath(root,targetSum)+ pathSum(root->left,targetSum)+ pathSum(root->right,targetSum);  
    }
};
//app2 using prefix sum

class Solution {
public:
    
    unordered_map<long long,int> mp;
    long long ans;
    
    void findPath(TreeNode* root,long long sum,long long targetSum){
        
        if(root==NULL)
            return ;
        
        long long currSum=sum+root->val;
        ans+=mp[currSum-targetSum];
        mp[currSum]+=1;
        
        findPath(root->left,currSum,targetSum);
        findPath(root->right,currSum,targetSum); 
        mp[currSum]-=1;
        
    }
 
    
    int pathSum(TreeNode* root, int targetSum) {
        
       if(root==NULL)
            return 0;
       mp[0]=1;
       ans=0;
       findPath(root,0,targetSum);  
       return ans;
    }
};
