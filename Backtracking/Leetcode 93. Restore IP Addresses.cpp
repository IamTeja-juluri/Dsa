class Solution {
public:
    
    vector<string> res;
    
    bool isValid(string x){
        
        int n=x.size();
        
        if(n!=1 && x[0]=='0'){
            return false;
        }
        
        int num=stoi(x);
        
        if(num>=0 && num<=255){
            return true;
        }
        
        return false;
        
    }
    
    void backTrack(string s,int idx,int c,string ans){
      
        if(idx==s.size() ){
            if(c==4){
               ans.pop_back();
              res.push_back(ans);   
            }
            return;
        }
        
        
        
        for(int i=idx;i<s.size();i++){
            
            string x=s.substr(idx,i-idx+1);
            
            if(x.size()<=3 && isValid(x)){
                
                x=x+'.';
                ans.append(x);
                backTrack(s,i+1,c+1,ans);
                
                int size=x.size();
                
                while(size--)
                ans.pop_back();
                
        
            }
                
        }
             
    }

    
    vector<string> restoreIpAddresses(string s) {
    
        backTrack(s,0,0,"");
        return res;
    }
};
