class Solution {
    
    public long maxAltSum(int[] nums,long[][] dp,int idx,int sign){
        
        
        if(idx>=nums.length)
            return 0;
        
        if(dp[idx][sign]!=-1)
            return dp[idx][sign];
       
        if(sign==1)
            return dp[idx][sign]=Math.max(nums[idx]+maxAltSum(nums,dp,idx+1,1-sign),maxAltSum(nums,dp,idx+1,sign));
        
       return dp[idx][sign]=Math.max(-nums[idx]+maxAltSum(nums,dp,idx+1,1-sign),maxAltSum(nums,dp,idx+1,sign));
    }

    
    public long maxAlternatingSum(int[] nums) {
     
        int n=nums.length;
        long[][] dp=new long[n][2];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<2;j++)
                dp[i][j]=-1;
        
        return maxAltSum(nums,dp,0,1);
    }
}
