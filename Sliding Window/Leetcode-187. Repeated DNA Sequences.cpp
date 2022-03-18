class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
     
        unordered_map<string,int> mp;
        vector<string> res;
        
        for(int i=0,j=9;j<s.size();i++,j++){
            string x=(s.substr(i,10));
            mp[x]+=1;
            
        }        
            
        
        for(auto it:mp){
            if(it.second>1)
                res.push_back(it.first);
        }
        
    
        return res;
        
    }
};
