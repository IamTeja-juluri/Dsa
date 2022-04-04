class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       
        int n=nums.size();
        int sum=0;
        unordered_map<int,int> mp;
        
        int count=0;
        
        for(int i=0;i<n;i++){
            
            sum+=nums[i];
            if(sum==goal)
                count+=1;
            if(mp.find(sum-goal)!=mp.end())
                count+=mp[sum-goal];
            mp[sum]+=1;
        }
        
        return count;
        
        
    }
};
