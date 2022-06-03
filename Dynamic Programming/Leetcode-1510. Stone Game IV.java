class Solution {
    
    int findWinner(int[] dp,int n){
       
       if(n==0)
           return 0;
       
       if(dp[n]!=-1)
           return dp[n];
       
       for(int i=1;i*i<=n;i++){
           
           if( n-i*i >= 0){
               int res=findWinner(dp,n-i*i);
               if(res==0)
                   return dp[n]=1;
           }
           
       }
       
       return dp[n]=0;
   }
    
    
    
    public boolean winnerSquareGame(int n) {
     
        int[] dp=new int[n+1];
        
        Arrays.fill(dp,-1);
        
        int res= findWinner(dp,n);
        if(res==0)
            return false;
        return true;
    }
}
