class Solution {
public:
    
  
    int f(int i,vector<int>& nums,vector<int>& dp,int end)
    {
        if(i>end)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        if(i==end)
            return nums[end];

        int pick=nums[i]+f(i+2,nums,dp,end);
        int notpick=f(i+1,nums,dp,end);
    
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        
        if(n==0)
            return 0;
        
        if(n==1)
            return nums[0];
        
        vector<int> dp(n,-1);
        int a=f(0,nums,dp,n-2);
        
        fill(dp.begin(), dp.end(),-1);
        int b=f(1,nums,dp,n-1);
        return max(a,b);        
    }
};
