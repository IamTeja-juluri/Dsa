//rec+memo
class Solution {
public:
    
    vector<vector<int> > dp;
    
    int helper(int i,int j,int n,int m,vector<vector<int> >&mat){
      
      if(i>=n or j>=m or j<0)
          return 1e9;
        
        if(i==n-1)
            return mat[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
      
      return dp[i][j]=mat[i][j]+min({helper(i+1,j-1,n,m,mat),helper(i+1,j,n,m,mat),helper(i+1,j+1,n,m,mat)}); 
        
    }
  
  int minFallingPathSum(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        dp.resize(n,vector<int>(m,-1));
        
        int ans=INT_MAX;
        
        for(int i=0;i<m;i++)
            ans=min(ans,helper(0,i,n,m,mat));
        
        return ans;
        
    }
  
  //Tabulation
   int minFallingPathSum(vector<vector<int>>& dp) {
        
        int n=dp.size();
        int m=dp[0].size();
        
        int ans=INT_MAX;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0)
                    dp[i][j]=dp[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                else if(j==m-1)
                    dp[i][j]=dp[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                else
                    dp[i][j]=dp[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
            }
        }
       
        for(int i=0;i<m;i++)
            ans=min(ans,dp[n-1][i]);
        
        return ans;
    }
        
    
};
