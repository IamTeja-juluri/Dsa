class Solution {
public:
    
    int longestLine(vector<vector<int>> &mat) {
        // Write your code here
        
        int n=mat.size();
        if(n==0)
         return 0;
        int m=mat[0].size();
        
        vector<vector<vector<int> > > dp;

        dp.resize(n,vector<vector<int> >(m, vector<int>(4,0)));

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(mat[i][j]==1){
                    
                    for (int k = 0; k < 4; k++) 
                       dp[i][j][k] = 1;
                
                    if(j-1>=0)
                       dp[i][j][0]+=dp[i][j-1][0];
                       
                    if(i-1>=0)
                       dp[i][j][1]+=dp[i-1][j][1];
                      
                    if(i-1>=0 && j-1>=0 )
                       dp[i][j][2]+=dp[i-1][j-1][2];
                   
                    if(i-1>=0 && j+1<m )
                       dp[i][j][3]+=dp[i-1][j+1][3];

                    ans=max({ans,dp[i][j][0],dp[i][j][1],dp[i][j][2],dp[i][j][3]});   
                }
            }
        }
        
        return ans;

    }
};
