class Solution {
    
    int helper(int[] piles,int[][] dp,int idx,int m){
        
        if(idx>=piles.length)
            return 0;
        
        if(dp[idx][m]!=-1)
            return dp[idx][m];
        
        int ans=Integer.MIN_VALUE;
        int total=0;
        
        for(int j=0;j<2*m;j++){
            
            if(idx+j < piles.length)
                total+=piles[idx+j];
            
            ans=Math.max(ans,total-helper(piles,dp,idx+j+1,Math.max(m,j+1)));
        }
        
        return dp[idx][m]=ans;
    }
    
    
    public int stoneGameII(int[] piles) {
        
        int sum=0;
        int n=piles.length;
        
        for(int x:piles)
            sum+=x;
        
        int[][] dp =new int[n][2*n+1];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=2*n;j++)
                dp[i][j]=-1;
        }
        
        int diff=helper(piles,dp,0,1);
        
        return (sum+diff)/2;
    
    }
}
