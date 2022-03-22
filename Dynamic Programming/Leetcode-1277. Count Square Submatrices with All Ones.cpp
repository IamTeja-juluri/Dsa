class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        
        
        int n=mat.size();
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<mat[i].size();j++){
                
                if(i==0 || j==0)
                    continue;
                
                if(mat[i][j]){
                    int mini=min(mat[i-1][j-1],min(mat[i][j-1],mat[i-1][j]));
                    mat[i][j]=1+mini;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<mat[i].size();j++){
                count+=mat[i][j];
            }
        }
        
        
        return count;
    }
};
