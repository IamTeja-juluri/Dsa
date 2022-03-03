class Solution {
public:
    
    bool isValid(int x,int y,char ch,vector<vector<char>>&board){
        
        //Along col
        
        for(int i=0;i<board.size();i++){
            if(board[i][y]==ch){
                return false;
            }
        }
        
        //Along row
        
        for(int j=0;j<board[0].size();j++){
            if(board[x][j]==ch){
                return false;
            }
        }
        
        int spx=(x/3)*3,spy=(y/3)*3;
        
        //Along grid
        for(int i=spx;i<spx+3;i++){
            for(int j=spy;j<spy+3;j++){
                if(board[i][j]==ch){
                    return false;
                }
            }
        }
        
        
        return true;
        
    }
    
    
    bool sudokoSolver(int i,int j,vector<vector<char>>&board){
        
        if(j==board[0].size()){
            
            if(i==board.size()-1){
                return true;
            }
            j=0;
            i=i+1;
        }
        
        
        if(board[i][j]!='.'){
            return sudokoSolver(i,j+1,board);
        }
        
        string s="123456789";
        
        for(int x=0;x<9;x++){
            
            char k=s[x];
            
            if(isValid(i,j,k,board)){
                board[i][j]=k;
                bool success=sudokoSolver(i,j+1,board);
                if(success)
                    return true;
                board[i][j]='.';
            }
            
        }
        
        return false;
        
    }
    
    
    
    void solveSudoku(vector<vector<char>>& board) {
        
        bool res=sudokoSolver(0,0,board);
        
    }
};
