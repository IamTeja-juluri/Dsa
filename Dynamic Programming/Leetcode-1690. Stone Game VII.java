//standard template
class Solution {
    
    int computeDifference(int[] stones,int[] pref,int[][] dp,int i,int j){
        
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
                                   //we use minus here because both of them wants to minimise score for each other- just remember trick for two player games
                                   // otherwise we can take boolean and for alice turn we take maximum and for bobs turn we take minimum
        int op1=pref[j+1]-pref[i+1]-computeDifference(stones,pref,dp,i+1,j);
        int op2=pref[j]-pref[i]-computeDifference(stones,pref,dp,i,j-1);
        
        return dp[i][j]=Math.max(op1,op2);
        
    }
    
    
    public int stoneGameVII(int[] stones) {
        
        int n=stones.length;
        int[][] dp=new int[n][n];
        int[] pref=new int[n+1];
      
        for(int i=0;i<n;i++)
            pref[i+1]=stones[i]+pref[i];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        
       return computeDifference(stones,pref,dp,0,n-1);
        
        
    }
}
