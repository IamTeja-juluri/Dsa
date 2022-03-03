class Solution {

public:
    
      vector<vector<int>> dp;  
    int lps(string &s,int i,int j){
        
        if(i>j){
            return 0;
        }
        
         else if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        else if(i==j){
            return dp[i][j]=1;
        }
        
       
        else{
            if(s[i]==s[j]){
            
            return dp[i][j]=2+lps(s,i+1,j-1);
            }
            else{   
                int l=lps(s,i+1,j);
                int r=lps(s,i,j-1);
                return dp[i][j]=max(l,r);
            }
        }
        
    }
    
    int longestPalindromeSubseq(string s) {
        
      int n=s.size();
      dp=vector<vector<int>>(n,vector<int>(n,-1));
      return lps(s,0,n-1); 
        
    }
};