class Solution {
public:
     
    vector<vector<int> > dp;
    
    int mod; 
    Solution(){
        mod=1e9+7;
    }
    
    int countWays(int n,int k,int target){
        
        if(n==0){
            if(target==0)
              return 1;
            return 0;
        }
        
        if(dp[n][target]!=-1)
            return dp[n][target];
        
        int ans=0;
        
        for(int i=1;i<=k;i++){
            if( target-i >= 0 )
                ans=(ans+countWays(n-1,k,target-i))%mod;
        }
        
        return dp[n][target]=ans;
    }
    
    
    int numRollsToTarget(int n, int k, int target) {
        
        dp.resize(n+1,vector<int>(target+1,-1));
        return countWays(n,k,target);
    }
};
