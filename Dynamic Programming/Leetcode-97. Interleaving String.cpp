class Solution {
public:
    
    vector<vector<vector<int> > > dp;
     
    bool findout(string &s1,string &s2,string &s3,int n,int m,int o){
        
        if(o==-1 && n==-1 && m==-1)
            return true;
        
        if(dp[n+1][m+1][o+1]!=-1)
            return dp[n+1][m+1][o+1];
       
        if( n>=0  &&  m>=0 && o>=0 && s1[n]==s3[o] && s2[m]==s3[o] )
              return dp[n+1][m+1][o+1]=findout(s1,s2,s3,n-1,m,o-1)||findout(s1,s2,s3,n,m-1,o-1);
         
        if(n>=0 && o>=0 && s1[n]==s3[o])
            return dp[n+1][m+1][o+1]=findout(s1,s2,s3,n-1,m,o-1);
        
         if(m>=0 && o>=0 && s2[m]==s3[o])
            return dp[n+1][m+1][o+1]=findout(s1,s2,s3,n,m-1,o-1);
        
        return false;
    }
    
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n=s1.size();
        int m=s2.size();
        int o=s3.size();
        
        if((n+m)!=o)
            return false;
        
        dp.resize(n+1,vector<vector<int> >(m+1,vector<int>(o+1,-1)));
        
        return findout(s1,s2,s3,n-1,m-1,o-1);
    }
};
//another way with same logic
class Solution {
public:
    
    vector<vector<vector<int> > > dp;
     
    bool findout(string &s1,string &s2,string &s3,int n,int m,int o){
        
        if(o==0 && n==0 && m==0)
            return true;
        
        if(dp[n][m][o]!=-1)
            return dp[n][m][o];
       
        if( n!=0  &&  m!=0 && o!=0 && s1[n-1]==s3[o-1] && s2[m-1]==s3[o-1] )
              return dp[n][m][o]=findout(s1,s2,s3,n-1,m,o-1)||findout(s1,s2,s3,n,m-1,o-1);
         
        if(n!=0 && o!=0 && s1[n-1]==s3[o-1])
            return dp[n][m][o]=findout(s1,s2,s3,n-1,m,o-1);
        
         if(m!=0 && o!=0 && s2[m-1]==s3[o-1])
            return dp[n][m][o]=findout(s1,s2,s3,n,m-1,o-1);
        
        return false;
    }
    
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n=s1.size();
        int m=s2.size();
        int o=s3.size();
        
        if((n+m)!=o)
            return false;
        
        dp.resize(n+1,vector<vector<int> >(m+1,vector<int>(o+1,-1)));
        
        return findout(s1,s2,s3,n,m,o);
    }
};
