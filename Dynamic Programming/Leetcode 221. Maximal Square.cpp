class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        
        int r=mat.size();
        int c=mat[0].size();
        
        if(r==0) return 0;
      
        vector<vector<int> >board(r+1,vector<int>(c+1,0));
     
        
        int ans=0;
        
        for(int i=1;i<board.size();i++){
            for(int j=1;j<board[0].size();j++){
                if(mat[i-1][j-1]=='1'){
                 board[i][j]=1+min(board[i][j-1],min(board[i-1][j],board[i-1][j-1]));
                 ans=max(ans,board[i][j]);
                }
            }
        }
        
        return ans*ans;
        
    }
};