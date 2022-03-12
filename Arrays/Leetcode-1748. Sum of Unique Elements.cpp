class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int> mp;
        
        for(auto x:nums)
            mp[x]+=1;
        
        int ans=0;
        
        for(auto it:mp){
            if(it.second==1)
                ans=ans+it.first;
        }
        
        return ans;
    }
};
