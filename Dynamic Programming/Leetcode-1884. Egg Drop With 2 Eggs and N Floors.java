class Solution {
    
    public int findMoves(int n,int k,int[][] dp){
        
        if(n<=1)
            return n;
        
        if(k==1)
            return n;
        
        if(dp[n][k]!=-1)
            return dp[n][k];
        
        int ans=Integer.MAX_VALUE;
        
        for(int i=1;i<n;i++)
            ans=Math.min(ans,Math.max(findMoves(i-1,k-1,dp),findMoves(n-i,k,dp))+1);
        
        
        return dp[n][k]=ans;
    }
    
    public int twoEggDrop(int n) {
        
        int k=2;
        
        int[][] dp=new int[n+1][k+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++)
                dp[i][j]=-1;
        }
        
        return findMoves(n,k,dp);
    }
}
