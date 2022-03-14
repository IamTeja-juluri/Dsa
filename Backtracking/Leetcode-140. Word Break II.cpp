class Solution {
public:
    
    vector<string> res;
    unordered_map<string,int> mp;
    
    void backtrack(string &s,string ans,int idx){
        
        if(idx==s.size()){
            ans.pop_back();
            res.push_back(ans);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            
            string substring=s.substr(idx,i-idx+1);
            if(mp.find(substring)!=mp.end()){
                backtrack(s,ans+substring+" ",i+1);
            }
            
        }
        
        return;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        
        for(auto x:wordDict)
            mp[x]+=1;
    
        backtrack(s,"",0);
        
        return res;
        
    }
};
