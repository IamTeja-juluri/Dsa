//iterative-gives tle
 int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        
        vector<int> dp(n);
        dp[0] = 1;
        int ans = dp[0];
        
        for (int i=1; i < n; i++) {
            int mx = 0;
            for (int j=0; j < i; j++) {
                if (intervals[i][0] >= intervals[j][1]) {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }

            ans = max(ans, dp[i]);
        }
            
        return n-ans;
    }
    //dp-gives tle
        vector<int> dp;
    
    int longestChain(vector<vector<int> > &nums,int idx){
        
        if(idx>=nums.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int ans=1;
        
        for(int i=idx+1;i<nums.size();i++){
            if(nums[i][0]>=nums[idx][1]){
                int subprob=1+longestChain(nums,i);
                ans=max(ans,subprob);
            }
        }
        
        return dp[idx]=ans;
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
      
        sort(nums.begin(),nums.end());
        int n=nums.size();
        dp.resize(n,-1);
        int res=0;
        
        for(int i=0;i<n;i++){
            res=max(res,longestChain(nums,0));
        }
        
        
        int ans=n-res;
        
        return ans;
    }
