class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        
        
        unordered_map<int,int> mp;
        int n=nums.size();
        int sum=0;
        int count=0;
        mp[0]=-1;
        int end=-1;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-target)!=mp.end() and mp[sum-target]>=end){
                end=i;
                count+=1;
            }
            mp[sum]=i;
        }
        
      return count;
        
    }
};
