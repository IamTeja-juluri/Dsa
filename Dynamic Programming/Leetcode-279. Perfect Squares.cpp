class Solution {
public:
    
    vector<int> dp;
    
    int perfectsquares(int n,int num){
        
        if(num>n)
            return INT_MAX-1;
        
        if(num==n)
            return 0;
        
        if(dp[num]!=-1)
            return dp[num];
        
        int ans=INT_MAX;
        
        for(int i=1;i*i<=n;i++){
            int subprob=perfectsquares(n,num+i*i);
            ans=min(ans,subprob+1);        
        }
    
        return dp[num]=ans;
    }
    
    
    
    int numSquares(int n) {
        
        dp.resize(n+1,-1);
        
        return perfectsquares(n,0);
        
    }
};
