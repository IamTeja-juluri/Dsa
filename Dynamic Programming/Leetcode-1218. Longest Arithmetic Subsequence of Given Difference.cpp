 int longestSubsequence(vector<int>& arr, int diff) {
        
        unordered_map<int,int> mp;
        int ans=1;
        
        for(int i=0;i<arr.size();i++){
            int prev=arr[i]-diff;
            if(mp.find(prev)!=mp.end())
                mp[arr[i]]=mp[prev]+1;
            else
                mp[arr[i]]=1;
        }
        
        for(auto x:mp)
            ans=max(x.second,ans);
        
        return ans;
    }
