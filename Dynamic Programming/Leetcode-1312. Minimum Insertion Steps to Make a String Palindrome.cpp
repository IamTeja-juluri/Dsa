//Find length of longest palindromic subsequence 
// string length minus lps length will be the minimum number of insertions it would take make string palindrome
class Solution {
public:
    
    vector<vector<int> > dp;
    
    int lps(string &s,int l,int r){
        
        if(l>r)
            return 0;
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        if(l==r)
            return dp[l][r]=1;
        
        if(s[l]==s[r])
            return dp[l][r]=2+lps(s,l+1,r-1);
        
        return dp[l][r]=max(lps(s,l+1,r),lps(s,l,r-1));
    }

    
    
    int minInsertions(string s) {
        
        int n=s.size();
        
        dp.resize(n,vector<int>(n,-1));
        
        int x=lps(s,0,n-1);
        
        return n-x;
        
    }
};
