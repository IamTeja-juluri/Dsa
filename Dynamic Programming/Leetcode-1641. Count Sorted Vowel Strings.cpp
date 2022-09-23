class Solution {
public:
    
    vector<vector<int> > dp;
    
    int helper(int idx,int l,int n){
        
        if(l==n)
            return 1;
        
        if(idx>4)
            return 0;
          
        if(dp[idx][l]!=-1)
            return dp[idx][l];
        
        int op1=0,op2=0;
        
        if(l<n)
            op1=helper(idx,l+1,n);
       
        op2=helper(idx+1,l,n);
        
        return dp[idx][l]=op1+op2;
    
    }
    
    int countVowelStrings(int n) {
        
        dp.resize(5,vector<int>(n,-1));
        
        return helper(0,0,n);
        
    }
};
