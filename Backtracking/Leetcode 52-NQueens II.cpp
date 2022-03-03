class Solution {
public:
    
    bool isValid(int l,int r,int n,vector<vector<int>>&board){
        
        int i=0,j=0;
        
        // along col
        
        while(i<n){
            if(board[i][r]==1){
                return false;
            }
            i+=1;
        }
        
        // along row
        while(j<n){
            if(board[l][j]==1){
                return false;
            }
            j+=1;
        }
        
       // along topleft dig
        
        i=l,j=r;
        
        while(i>=0 && j>=0){
            if(board[i][j]==1){
                return false;
            }
            i-=1;
            j-=1;
        }
        
        // along topright dig
        
        i=l,j=r;
        
        while(i>=0 && j<n){
            if(board[i][j]==1){
                return false;
            }
            i-=1;
            j+=1;
        }
        
        return true;
    }
    
    int totalways(int i,int n,vector<vector<int>>&board){
        
        if(i==n){
            return 1;
        }
        
        int ways=0;
        
        for(int j=0;j<n;j++){
            if(isValid(i,j,n,board)){
                board[i][j]=1;
                ways+=totalways(i+1,n,board);
                board[i][j]=0;
            }
        }
        return ways;
    }
    
    
    int totalNQueens(int n) {
        
        
       vector<vector<int> >board(n,vector<int>(n,0)); 
       
       return totalways(0,n,board);
     
        
    }
};
