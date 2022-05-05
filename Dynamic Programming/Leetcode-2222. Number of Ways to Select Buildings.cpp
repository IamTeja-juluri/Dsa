class Solution {
public:
    
  long long dp[100005][4][4];
    
    long long countways(string &s,int idx,int cnt,char prev){
        
        if(cnt==3)
            return 1;
        
        if(idx==s.size())
            return 0;
        
        if(dp[idx][cnt][prev-'0']!=-1)
            return dp[idx][cnt][prev-'0'];
        
        if(s[idx]!=prev)
            return dp[idx][cnt][prev-'0']=countways(s,idx+1,cnt+1,s[idx])+countways(s,idx+1,cnt,prev);
        
        return dp[idx][cnt][prev-'0']=countways(s,idx+1,cnt,prev);
    }
    
    
    long long numberOfWays(string s) {
        
       memset(dp,-1,sizeof dp);
        return countways(s,0,0,'2');
    }
};
