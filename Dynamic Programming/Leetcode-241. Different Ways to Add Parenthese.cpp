class Solution {
public:
    
    vector<int> diffWaysToCompute(string s) {
        
      vector<int> ans;
        
      for(int i=0;i<s.size();i++){
            if(s[i]=='+' or s[i]=='*' or s[i]=='-'){
                vector<int> left=diffWaysToCompute(s.substr(0,i));
                vector<int> right=diffWaysToCompute(s.substr(i+1));
                for(auto x:left){
                    for(auto y:right){
                        if(s[i]=='+')
                            ans.push_back(x+y);
                        else if(s[i]=='-')
                            ans.push_back(x-y);
                        else if(s[i]=='*')
                            ans.push_back(x*y);
                    }
                }
             
            }
        }
        
        if(ans.size()==0 )
            ans.push_back(stoi(s));
        return ans;
    }
};
