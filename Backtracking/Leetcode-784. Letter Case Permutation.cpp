class Solution {
public:
    vector<string> res;
    
    void permute(string s,int idx){
        
        if(idx==s.size()){
            res.push_back(s);
            return;
        }
        
        if(!(s[idx]>=48 && s[idx]<=57)){
           s[idx]=s[idx]^32;
           permute(s,idx+1);
           s[idx]=s[idx]^32;
        }
        
        permute(s,idx+1);
        
    }
    
    
    
    vector<string> letterCasePermutation(string s) {
     
        permute(s,0);
        return res;
    }
};
