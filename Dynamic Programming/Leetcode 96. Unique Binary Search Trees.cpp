class Solution {
public:
    
    vector<int> dp;
    
    int nthCatalan(int n){
        
        if(n<=0){
            return 1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        long long ans=0;
        
        for(int i=0;i<n;i++){
            ans=ans+nthCatalan(n-i-1)*nthCatalan(i);
        }
        
        return dp[n]=ans;
        
    }
    
    int numTrees(int n) {
         
        dp.resize(n+1,-1);
        
        return nthCatalan(n);
        
    }
};
