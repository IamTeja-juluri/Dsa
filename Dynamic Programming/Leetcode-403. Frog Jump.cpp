class Solution {
public:
    
    unordered_map<int,int>mp;
    vector<vector< int > > dp;
    
    bool canfrogjump(vector<int>&stones,int k,int idx){
        
        if(idx==stones.size()-1)
            return true;
        
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        
        if(mp.find(stones[idx]+k)==mp.end() || k==0)
            return false;
        
        int pos=mp[stones[idx]+k];
        
        bool op1=canfrogjump(stones,k-1,pos);
        bool op2=canfrogjump(stones,k,pos);
        bool op3=canfrogjump(stones,k+1,pos);
       
        if(!op1 && !op2 && !op3)
            return dp[idx][k]=0;
        
        return dp[idx][k]=1;
    }
    
    
    bool canCross(vector<int>& stones) {
        
        int n=stones.size();
        
        for(int i=0;i<n;i++)
            mp[stones[i]]=i;
        
        dp.resize(n+1,vector<int>(n+1,-1));
        
        return canfrogjump(stones,1,0);
    }
};
