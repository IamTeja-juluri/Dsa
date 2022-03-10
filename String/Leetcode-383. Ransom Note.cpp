class Solution {
public:
    bool canConstruct(string r, string m) {
     
        unordered_map<char,int> mp;
        
        for(auto x:m)
            mp[x]++;
        
        for(auto x:r){
            if(mp.find(x)!=mp.end()){
                mp[x]--;
                if(mp[x]==0)
                    mp.erase(x);
            }
            else
                return false;
        }
        return true;
        
    }
};
