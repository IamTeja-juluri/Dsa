class Solution {
public:
    
    
    vector<int> dp;
    
    int helper(vector<int>&nums,int idx,int n){
        
        if(idx>=n)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
         int ans=INT_MIN;
        
         ans=max(ans,nums[idx]-helper(nums,idx+1,n));
        
         if(idx<(n-1))
            ans=max(ans,nums[idx]+nums[idx+1]-helper(nums,idx+2,n));
        
         if(idx<(n-2))
            ans=max(ans,nums[idx]+nums[idx+1]+nums[idx+2]-helper(nums,idx+3,n));
        
     
        return dp[idx]=ans;
        
    }
    
    
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n=stoneValue.size();
        
      
        dp.resize(n+10,-1);
        
        string ans="Tie";
        
        int diff=helper(stoneValue,0,n);
        
        
        if(diff>0)
            ans="Alice";
         
        if(diff<0)
            ans="Bob";
        
        return ans;
    }
};
