class Solution {
public:
    vector<vector<vector<int>>>dp;
    
    pair<int,int>fun(string &s){
        
        int n=s.size();
        int count=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
               count++;   
            }
        }
        
        return {count,n-count};
    }
    
    
    int LargeSubset(vector<string>&strs,int m,int n,int idx){
        
        int size=strs.size();
        
        if(idx==size || (m+n)==0)
            return 0;
        
        if(dp[m][n][idx]!=-1)
            return dp[m][n][idx];
        
        int l=0,r=0;
        pair<int,int>p=fun(strs[idx]);
        
        int f=p.first;
        int s=p.second;
        
        if(f<=m && s<=n)
        l=1+LargeSubset(strs,m-f,n-s,idx+1);  
        
        r=LargeSubset(strs,m,n,idx+1);
        
        return dp[m][n][idx]=max(l,r);
    }
   
    
    int findMaxForm(vector<string>&strs, int m, int n) {
        int size=strs.size();
        dp=vector<vector<vector<int>>>(m+1,vector<vector<int>>(n+1,vector<int>(size,-1)));
        return LargeSubset(strs,m,n,0);
    }
};
