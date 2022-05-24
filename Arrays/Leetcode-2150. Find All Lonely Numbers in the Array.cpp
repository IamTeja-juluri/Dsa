class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        vector<int> res;
        
        unordered_map<int,int> mp;
        
        for(auto x:nums)
            mp[x]+=1;
            
        for(auto it:mp){
            if(it.second==1)
                if( (mp.find(it.first + 1)==mp.end() ) && (mp.find(it.first - 1)==mp.end() ) )
                    res.push_back(it.first);
        }    
        
        
        return res;
    }
};
