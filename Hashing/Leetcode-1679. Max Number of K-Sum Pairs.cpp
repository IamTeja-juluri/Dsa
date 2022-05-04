class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            if(mp.find(k-nums[i])!=mp.end()){
                count+=1;
                mp[k-nums[i]]-=1;
                if(mp[k-nums[i]]==0)
                 mp.erase(k-nums[i]);
            }else
               mp[nums[i]]+=1;
        }
        
        return count;
    }
};
