class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int count=0;
        
        unordered_map<int,int> mp;
        
        for(auto x:time){
            
            int mod=x%60;
            
            if(mod==0 && mp.find(0)!=mp.end())
                    count+=mp[0];
            
            else if(mp.find(60-mod)!=mp.end())
                    count+=mp[60-mod];
            
            mp[mod]++;
        }
        
        return count;
    }
};
