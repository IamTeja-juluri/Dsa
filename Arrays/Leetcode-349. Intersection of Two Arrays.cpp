class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        
        set<int> st;
        unordered_map<int,int> mp;
        
        
        for(auto x:nums1)
            st.insert(x);
        
        for(auto x:nums2)
            mp[x]++;
        
        for(auto x:st){
            if(mp.find(x)!=mp.end())
                res.push_back(x);
            
        }
            
        return res;
        
        
    }
};
