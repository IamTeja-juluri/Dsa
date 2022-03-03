class Solution {
public:
    
    vector<int> dp;
    
    unordered_map<string,int> mp;
    
    bool search(string s,int idx){
        
        if(idx==s.size()){
            return true;
        }
       
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        for(int i=idx;i<s.size();i++){
            
            int len=i-idx+1;
            string temp=s.substr(idx,len);
            if(mp.find(temp)!=mp.end()){
                
                bool res=search(s,i+1);
                if(res){
                    return dp[i]=true;
                }
                    
            }
            
            
        }
        
        return dp[idx]=false;
        
    }
    
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
     
        dp=vector<int> (s.size(),-1);
        for(auto x:wordDict){
            mp[x]+=1;
        }
        
        return search(s,0);
    
    }
};