class Solution {
public:
    
    vector<int> dp;
    
    int helper(int n){
        
        if(n==1)
            return 1;
        
        if(n<=3)
            return n;
        
        if(dp[n]!=-1)
            return dp[n];
       
        int ans=0;
        
        for(int i=1;i<=(n/2);i++)
           ans=max(ans,helper(n-i)*helper(i));
        
        return dp[n]=ans;
    }
    
    int integerBreak(int n) {
        
        if(n<=2)
            return 1;
        
        if(n==3)
            return 2;
        
       dp.resize(n+1,-1);
        
       return helper(n); 
      
    }
};
