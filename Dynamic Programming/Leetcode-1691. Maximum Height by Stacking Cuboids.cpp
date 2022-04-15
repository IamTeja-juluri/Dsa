class Solution {
public:
    
    int dp[105];
    
    int computeMaxHeight(vector<vector<int> > &cuboids,int idx){
        
        if(idx>=cuboids.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int ans=cuboids[idx][2];
        
        for(int j=idx+1;j<cuboids.size();j++){
           if(cuboids[j][0]>=cuboids[idx][0] && cuboids[j][1]>=cuboids[idx][1] && cuboids[j][2]>=cuboids[idx][2])
               ans=max(ans,cuboids[idx][2]+computeMaxHeight(cuboids,j));
        }
        
        return dp[idx]=ans;
      
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        
        for(int i=0;i<cuboids.size();i++)
            sort(cuboids[i].begin(),cuboids[i].end());
    
        sort(cuboids.begin(),cuboids.end());
        int ans=0;    
        memset(dp,-1, sizeof dp);
        for(int i=0;i<cuboids.size();i++){
            ans=max(ans,computeMaxHeight(cuboids,i));
        }
        
        return ans;
    }
};
