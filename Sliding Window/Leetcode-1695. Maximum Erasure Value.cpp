class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        int ans=0;
        int sum=0;
        int j=0;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=1;
            ans=max(ans,sum);
            while(mp[nums[i]]>1){
               mp[nums[j]]-=1;
               sum-=nums[j];
               j+=1;
            }
            sum+=nums[i];
        }
        ans=max(ans,sum);
        return ans;
    }
};
