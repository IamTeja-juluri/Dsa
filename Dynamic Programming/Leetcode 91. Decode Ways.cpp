class Solution {
public: 
     vector<int> dp;
    
    int countWays(string s,int i){
        
        if(i==s.size()){
            return 1;
        }
        
        if(s[i]=='0'){
            return 0;
        }
                  
        if(i==s.size()-1){
            return 1;
        }
       
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        string str=s.substr(i,2);
        
        int l=countWays(s,i+1);
        int r=(stoi(str)>=1 && stoi(str)<=26)?countWays(s,i+2):0;
        
        return dp[i]=l+r;
        
    }

    
    int numDecodings(string s) {
        dp=vector<int> (s.size(),-1);
        return countWays(s,0);
        
    }
};