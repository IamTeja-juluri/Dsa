class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        unordered_map<int,int> mp;
        
        for(auto x:nums2)
            mp[x]+=1;
        
        for(auto x:nums1){
            if(mp.find(x)!=mp.end()){
                res.push_back(x);
                mp[x]--;
                if(mp[x]==0)
                    mp.erase(x);
            }
        }
        
        return res;
    }
};
