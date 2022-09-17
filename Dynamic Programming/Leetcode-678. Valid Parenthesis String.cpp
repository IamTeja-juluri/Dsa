class Solution {
public:

    vector<vector<int> > dp;
    
    int helper(string &s,int idx,int score){
        
       if(idx==s.size() or score<0){
           if(score==0)
               return true;
           return false;
       } 
        
       if(dp[idx][score]!=-1)
           return dp[idx][score];
        
       else if(s[idx]=='(')
           return helper(s,idx+1,score+1);
        
        else if(s[idx]==')')
            return helper(s,idx+1,score-1);
        
        return dp[idx][score]=helper(s,idx+1,score+1) || helper(s,idx+1,score-1) || helper(s,idx+1,score);
    }
    
    
    
    bool checkValidString(string s) {
        
       int n=s.size();
       dp.resize(n,vector<int>(n,-1)); 
        
       return helper(s,0,0); 
    }
    
};
