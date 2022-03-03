class Solution {
public:
    
    bool subsetSum(vector<int>&nums,int s,int n,vector<vector<int>>&dp){
        
        if(s==0){
            return true;
        }
        
        if(n==0){
            return false;
        }
        
        // if(s<0) return false;
        
        
        if(dp[n-1][s]!=-1){
            return dp[n-1][s];
        }
        
        if(nums[n-1]>s)
            return dp[n-1][s]=subsetSum(nums,s,n-1,dp);
       
        return dp[n-1][s]=subsetSum(nums,s-nums[n-1],n-1,dp) || subsetSum(nums,s,n-1,dp);
        
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int s=0;
        
        for(int x:nums){
            s+=x;
        }
        
        if((s%2)!=0) return false;
        vector<vector<int>> dp(n,vector<int>(s,-1));
        return subsetSum(nums,s/2,n,dp);
       
    }
};