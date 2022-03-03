class Solution {
public:
    
    int minJumps(vector<int>&nums,int idx,vector<int>&dp){
        
        int n=nums.size();
        
        if(idx==n-1) return 0;
        
        if(nums[idx]==0) return 1e9+7;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int ans=1e9+7;
        
        for(int i=idx+1;i<=idx+nums[idx];i++){
              if(i>=n) continue;
             ans=min(ans,1+minJumps(nums,i,dp)); 
        }
        
        return dp[idx]=ans;
        
    }
    
    int jump(vector<int>& nums) {
      
        int n=nums.size();
        
        vector<int>dp(n,-1);
       return minJumps(nums,0,dp);  
        
    }
};