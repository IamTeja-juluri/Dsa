//standard template 
//app1
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
//app2
//without prefix arr
//remember we dont need sum dimension for dp array-reason unknown ,it just works in quesns like dis
class Solution {
    
    int computeDifference(int[] stones,int sum,int[][] dp,int i,int j){
        
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int op1=sum-stones[i]-computeDifference(stones,sum-stones[i],dp,i+1,j);
        int op2=sum-stones[j]-computeDifference(stones,sum-stones[j],dp,i,j-1);
        
        return dp[i][j]=Math.max(op1,op2);
        
    }
    
    
    public int stoneGameVII(int[] stones) {
        
        int n=stones.length;
        int[][] dp=new int[n][n];
        int sum=0;
      
        for(int i=0;i<n;i++)
            sum+=stones[i];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        
       return computeDifference(stones,sum,dp,0,n-1);
        
        
    }
}
//app3
class Solution {
public:
    
    int dp[1000][1000][2];
    vector<int>pre,suf;
    
    int recurs(int i,int j,int chance)
    {
        if(i>j)
        {
            return 0;
        }
        
        if(dp[i][j][chance]!=-1)
        {
            return dp[i][j][chance];
        }
        
        if(chance==0)
        {
            return dp[i][j][chance]=max(recurs(i+1,j,1)+pre[j]-pre[i],recurs(i,j-1,1)+suf[i]-suf[j]);
        }
        if(chance==1)
        {
            return dp[i][j][chance]=min(recurs(i+1,j,0)-pre[j]+pre[i],recurs(i,j-1,0)-suf[i]+suf[j]);
        }
        
        return 0;
    }
    

    
    int stoneGameVII(vector<int>& stones) {
        
        memset(dp,-1,sizeof(dp));
        
        pre.resize(stones.size(),0);
        suf.resize(stones.size(),0);
        
        int sum=0;
        for(int i=0;i<stones.size();i++)
        {
            sum+=stones[i];
            pre[i]=sum;
        }
        sum=0;
        
        for(int i=stones.size()-1;i>=0;i--)
        {
            sum+=stones[i];
            suf[i]=sum;
        }
        
     
        int diff=recurs(0,stones.size()-1,0);

        return diff;
    }
};
