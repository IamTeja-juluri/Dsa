class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int i=0,s=0;
        int n=nums.size();
        if(n==0)
            return 0;
        int count=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            s+=nums[i];
            if(s==k)
                count+=1;
            if(mp.find(s-k)!=mp.end())
                count+=mp[s-k];
            mp[s]+=1;
            
        }
    return count;
    }
    
};
