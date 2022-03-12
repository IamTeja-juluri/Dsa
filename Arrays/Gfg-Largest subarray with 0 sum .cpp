class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> mp;
        
        int prf=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            prf+=A[i];
            
            if(prf==0)
             ans=max(ans,i+1);
            
            if(mp.find(prf)!=mp.end())
                ans=max(ans,i-mp[prf]);
                
            else
              mp[prf]=i;
        }
        
        return ans;
    }
};
