class Solution {
public:
    
    vector<vector<int> > dp;
    vector<int> memo;
    
    int isPalindrome(string &s,int l,int r){
       
        if(l>=r)
            return 1;
        else if(dp[l][r]!=-1)
            return dp[l][r];
        else if(s[l]!=s[r])
            return dp[l][r]=0;
        else
         return dp[l][r]=isPalindrome(s,l+1,r-1);
        
    }
    
    int palindromePartioning(string &s,int idx){
        
        if(idx>=s.size()-1)
            return 0;
        if(memo[idx]!=-1)
            return memo[idx];
        if(isPalindrome(s,idx,s.size()-1))
            return memo[idx]=0;
        int ans=INT_MAX;
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                int subprob=1+palindromePartioning(s,i+1);
                ans=min(ans,subprob);
            }
        }
        return memo[idx]=ans;
    }
    
    int minCut(string s) {
      memo.resize(s.size(),-1);
      dp.resize(s.size(),vector<int>(s.size(),-1));
     return palindromePartioning(s,0);   
    }
};