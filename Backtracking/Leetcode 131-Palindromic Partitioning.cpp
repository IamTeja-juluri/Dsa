class Solution {
public:
    
      bool isPalindrome(string s, int start, int end,vector<vector<int>>&dp) {
        
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        
        while(start <= end) {
            if(s[start++] != s[end--])
                return dp[start-1][end+1]=false;
        }
        return dp[start-1][end+1]=true;
    }
    
    void palindromePartition(int index, string s, vector<string> &path, 
              vector<vector<string> > &res,vector<vector<int>>&dp) {
        if(index == s.size()) {
            res.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i,dp)) {
                path.push_back(s.substr(index, i - index + 1));
                palindromePartition(i+1, s, path, res,dp);
                path.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> path;
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        palindromePartition(0, s, path, res,dp);
        return res;
    }
    
    
  
};
