class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
    long long sum=0;
    int target=0;
    int n=nums.size();
    int ans=INT_MAX;
        
    for(int i=0;i<nums.size();i++)
        target=(target+nums[i])%p;
        
    if(target==0)
        return 0;
        
    unordered_map<int,int>mp;
    mp[0]=-1;
        
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        int rem=sum%p;
         if(mp.find((rem-target+p)%p)!=mp.end())
         {
             int j=mp[(rem-target+p)%p];
                 ans=min(ans,i-j);
         }
        mp[rem]=i;
    }
    if(ans==INT_MAX||ans==n)
        return -1;
    return ans;
       
    }
};
