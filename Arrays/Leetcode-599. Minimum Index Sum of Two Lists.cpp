class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string,int> mp;
        vector<string> res;
        
        for(int i=0;i<list1.size();i++)
            mp[list1[i]]=i;
        
        int ans=INT_MAX;
        
        for(int i=0;i<list2.size();i++){
            if(mp.find(list2[i])!=mp.end())
                ans=min(ans,i+mp[list2[i]]);
        }
        
        for(int i=0;i<list2.size();i++){
            if(mp.find(list2[i])!=mp.end() and i+mp[list2[i]]==ans)
                res.push_back(list2[i]);
        }
        
        return res;
    }
};
