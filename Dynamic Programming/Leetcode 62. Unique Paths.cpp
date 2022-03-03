//Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int> > mat(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            mat[i][0]=1;
        }
        
        for(int j=0;j<n;j++){
            mat[0][j]=1;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j]=mat[i][j-1]+mat[i-1][j];
            }
        }
        
        return mat[m-1][n-1];
    }
};

//Memoization
class Solution {
public:
    
    int totalPaths(vector<vector<int> >&mat,int i,int j,vector<vector<int>>&dp){
        if(i==mat.size()-1 && j==mat[0].size()-1){
            return dp[i][j]=1;
        }
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j]=totalPaths(mat,i,j+1,dp)+totalPaths(mat,i+1,j,dp);
    }
    
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int> > mat(m,vector<int>(n,0));
        vector<vector<int> > dp(m,vector<int>(n,-1));
        
        
        return totalPaths(mat,0,0,dp);
        
    }
};