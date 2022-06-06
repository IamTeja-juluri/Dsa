class Solution {
public:
    
    unordered_map<int,vector<int> > mp;
    vector<vector<int> > dp;
    
       int helper(int idx,int n){
        
        int mod=1e9+7;
        
        if(n==1)
            return dp[idx][n]=1;
        
        if(dp[idx][n]!=-1)
            return dp[idx][n];
        
        int count=0;
        
        vector<int>v=mp[idx];
        
        for(int j=0;j<v.size();j++)
            count=((count%mod)+helper(v[j],n-1)%mod)%mod;
        
        return dp[idx][n]=count;
    }
    
    
    int knightDialer(int n) {
     
        int count=0;
        
        dp.resize(11,vector<int>(n+1,-1));
        
        mp[0]={4,6};
        mp[1]={8,6};
        mp[2]={7,9};
        mp[3]={4,8};
        mp[4]={9,3,0};
        mp[5]={};
        mp[6]={7,1,0};
        mp[7]={2,6};
        mp[8]={3,1};
        mp[9]={2,4};
        
        int mod=1e9+7;
        
        for(int i=0;i<=9;i++)
            count=((count%mod)+(helper(i,n)%mod))%mod;
        return count;
        
    }
};
