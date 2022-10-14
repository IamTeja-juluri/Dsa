class Solution {
public:
    
    int mod=1e9+7;
    vector<vector<int> > memo;
    
    int helper(int s,int e,int k){
        
        if(k==0){
            if(s==e)
                return 1;
            return 0;
        }
       
        if(memo[s+1000][k]!=-1)
            return memo[s+1000][k];
        
        int op1=helper(s+1,e,k-1);
        int op2=helper(s-1,e,k-1);
        
        return  memo[s+1000][k]=( op1%mod + op2%mod )%mod;
    }
    
    
    int numberOfWays(int s, int e, int k) {
        
       memo.resize(3005,vector<int>(1005,-1)); 
       return helper(s,e,k);
    }
};
