class Solution {
public:
    
    bool checkValidity(int l,int r,vector<vector<char>>&board){
        
        //Along row
        int count[60]={0};
        
        for(int j=0;j<board[0].size();j++){
            if(board[l][j]=='.'){
                continue;
            }
            int x=int(board[l][j]);
            count[x]+=1;
            if(count[x]>1){
                return false;
            }
        }
        
        int count1[60]={0};
        
        //Along col
        
        for(int i=0;i<board.size();i++){
            if(board[i][r]=='.'){
                continue;
            }
            int x=int(board[i][r]);
            count1[x]+=1;
            if(count1[x]>1){
                return false;
            }
        }
        
        // ALong grid
      int  count2[60]={0};
        
        int spx=(l/3)*3;
        int spy=(r/3)*3;
        
        for(int i=spx;i<spx+3;i++){
            for(int j=spy;j<spy+3;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                int x=int(board[i][j]);
                count2[x]+=1;
                if(count2[x]>1){
                    return false;
                }
            }
        }
        
        
        return true;
    }
    
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    continue;
                }
                bool res=checkValidity(i,j,board);
                if(res==false){
                    return false;
                }
            }
        }
        
        return true;
    
    }
};
