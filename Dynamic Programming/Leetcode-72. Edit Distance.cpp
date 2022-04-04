class Solution {
public:
    
    vector<vector<int> > dp;
    
    int minOperations(string &s1,string &s2,int n,int m){
        
        if(n==-1)
            return m+1;
        
        if(m==-1)
            return n+1;
        
        if(dp[n][m]!=-1)
            return dp[n][m];

        
        if(s1[n]==s2[m])
            return dp[n][m]=minOperations(s1,s2,n-1,m-1);
        
        int op2=1+minOperations(s1,s2,n-1,m-1); //replacing
        int op3=1+minOperations(s1,s2,n-1,m);   //delete
        int op4=1+minOperations(s1,s2,n,m-1);   //insert
        
        return dp[n][m]=min({op2,op3,op4});
        
    }
    

    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
        
        if(n==0)
            return m;
        
        if(m==0)
            return n;
        
        dp.resize(n+1,vector<int>(m+1,-1));
        
        return minOperations(word1,word2,n-1,m-1);
        
    }
};
