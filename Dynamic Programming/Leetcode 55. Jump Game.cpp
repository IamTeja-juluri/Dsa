class Solution {
public:
    bool jumpGame(vector<int>&nums,int idx,vector<int>&dp){
        
        int n=nums.size();
        
        if(idx>=n) return false;
        
        if(idx==n-1){
            return dp[idx]=1;
        }
        
        if(dp[idx]!=-1) return dp[idx];
        
          
        for(int i=1;i<=nums[idx];i++){
            
            if(jumpGame(nums,i+idx,dp)){
                return dp[idx]=1;
            }
            
        }
        
        return dp[idx]=0;
    }
    
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1 && nums[0]==0 ) return true;
        
        vector<int> dp(n,-1);
        return jumpGame(nums,0,dp);
    }
};