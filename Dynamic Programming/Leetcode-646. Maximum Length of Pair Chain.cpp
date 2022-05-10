//using dp
//refer backtracking app in backtracking section
class Solution {
public:
    
    vector<int>dp;
    
    int findMaxLen(vector<vector<int> > &pairs,int idx){
        
        if(idx==pairs.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
       
        int ans=0;
        
        for(int j=idx+1;j<pairs.size();j++){
            if(pairs[j][0]>pairs[idx][1])
                ans=max(ans,1+findMaxLen(pairs,j));    
            ans=max(ans,findMaxLen(pairs,j));
        }
       
        return dp[idx]=ans;
    }
 
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n=pairs.size();
        dp.resize(n+1,-1);
        sort(pairs.begin(),pairs.end());
         
        int ans=0;
        
        ans=findMaxLen(pairs,0);
       
        return ans+1;
    }
};
