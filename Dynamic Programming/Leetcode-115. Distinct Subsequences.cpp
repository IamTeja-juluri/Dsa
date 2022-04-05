class Solution {
public:
    
    vector<vector<int>>dp;
    
    int countSubsequences(string &s1,string &s2,int l,int r){
        
        if(r==-1)
            return 1;
        
        if(l==-1)
            return 0;
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        if(s1[l]==s2[r])
            return dp[l][r]=countSubsequences(s1,s2,l-1,r-1)+ countSubsequences(s1,s2,l-1,r);
           
        return dp[l][r]=countSubsequences(s1,s2,l-1,r);
        
    }
    
    int numDistinct(string s, string t) {
        
        int n=s.size();
        int m=t.size();
        
        dp.resize(n,vector<int>(m,-1));
        
        if(n==0 && m==0)
            return 1;
        
        if(n==0 || m==0)
            return 0;
        
        return countSubsequences(s,t,n-1,m-1);
    }
};
