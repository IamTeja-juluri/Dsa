class Solution {
public:
    
    bool jump(vector<int>&nums,int idx,vector<int>&dp){
        
        int n=nums.size();
        
        if(idx<0 || idx>=n){
            return false;
        }
        
        
        if(nums[idx]==0){
            return true;
        }
        
        if(dp[idx]==1) return false;
        
        dp[idx]=1;
        
        return jump(nums,idx+nums[idx],dp)||jump(nums,idx-nums[idx],dp);
        
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        vector<int> dp(n,0);
        return jump(arr,start,dp);
        
    }
};