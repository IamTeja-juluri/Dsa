class Solution {
public:
    
    vector<vector<int> > dp;
    int computeMinAscii(string &s1,string &s2,int n,int m){
        
        if(n==-1 || m==-1){
            int s=0;
            while(m!=-1){
                s=s+int(s2[m]);
                m-=1;
            }
             while(n!=-1){
                s=s+int(s1[n]);
                n-=1;
            }
            return s;
        }
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(s1[n]!=s2[m]){
            int op1=int(s1[n])+computeMinAscii(s1,s2,n-1,m);
            int op2=int(s2[m])+computeMinAscii(s1,s2,n,m-1);
            return dp[n][m]=min(op1,op2);
        }
        
        return dp[n][m]=computeMinAscii(s1,s2,n-1,m-1);
    }
    
    
    int minimumDeleteSum(string s1, string s2) {
        
        int n=s1.size();
        int m=s2.size();
        dp.resize(n,vector<int>(m,-1));
        
        return computeMinAscii(s1,s2,n-1,m-1);
    }
};
