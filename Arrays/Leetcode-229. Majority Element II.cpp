class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> res;
        unordered_map<int,int> mp;
        
        for(auto x:nums)
            mp[x]+=1;
        
        int n=nums.size();
            
        for(auto it:mp){
            if(it.second>(n/3))
                res.push_back(it.first);
        }
        
        
        return res;
    }
};
