class Solution {
public:
    vector<string> cellsInRange(string s) {
     
        char r1=s[1],r2=s[4];
        char c1=s[0],c2=s[3];
        
        
        vector<string> res;
        
        for(char chc=c1;chc<=c2;chc++){
            
            string ans;
            
            ans.push_back(chc);
            
            for(char chr=r1;chr<=r2;chr++){
                
                ans.push_back(chr);
                res.push_back(ans);
                ans.pop_back();
                
            }
    
        }
        
        
        return res;
        
    }
};
