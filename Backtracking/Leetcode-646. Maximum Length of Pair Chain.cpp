//using backtracking
class Solution {
public:
    
    vector<int> dp;
    vector<bool>visited;
    
    int backtrack(vector<vector<int>>&pairs,int idx){
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int ans=1;
        
        for(int i=0;i<pairs.size();i++){
            if(visited[i]==false && pairs[i][0]>pairs[idx][1]){
                visited[i]=true;
                ans=max(ans,1+backtrack(pairs,i));
                visited[i]=false;
            } 
        }
        
        return dp[idx]=ans;
    }
    
   
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n=pairs.size();
       
        dp.resize(n+1,-1);
        visited.resize(n+1,false);
        
        int ans=1;
        
        for(int i=0;i<n;i++){
            visited[i]=true;
            ans=max(ans,backtrack(pairs,i));
            visited[i]=false;
        }
        
      return ans;
        
    }
};
