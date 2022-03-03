class Solution {
public:
    
    vector<int> dp;
    
    int totalWays(vector<int>&nums,int target){
        
        if(target==0){
            return dp[target]=1;
        }
        
        if(target<0){
            return 0;
        }
        
        if(dp[target]!=-1){
            return dp[target];
        }
        
        int ans=0;
        
        for(auto x :nums){
            ans=ans+totalWays(nums,target-x);
        }
        return dp[target]=ans;
    }
    
     
    int combinationSum4(vector<int>& nums, int target) {
        
      dp=vector<int>(target+1,-1);
        return totalWays(nums,target); 
    }
};