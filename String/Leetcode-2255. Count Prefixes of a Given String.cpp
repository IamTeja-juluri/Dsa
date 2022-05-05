class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
     
        int cnt=0;
        
        unordered_map<string,int> mp;
        
        for(auto x:words)
            mp[x]+=1;
        
        for(int i=0;i<s.size();i++){
            string s1=s.substr(0,i+1);
            if(mp.find(s1)!=mp.end())
                cnt+=mp[s1];
        }
        
        return cnt;
    }
};
