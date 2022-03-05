class Solution {
public:
    
   void dfs(vector<vector<char> > &board,int x,int y){
       
       int n=board.size();
       int m=board[0].size();
       
     /*  if(x<0 || x>=n || y<0 || y>=m  || board[x][y]!='X'){
           return ;
       }
       
       board[x][y]='.';
       
       dfs(board,x-1,y);
       dfs(board,x+1,y);
       dfs(board,x,y+1);
       dfs(board,x,y-1); */
       
       
       int dx[]={1,-1,0,0};
       int dy[]={0,0,1,-1};
       
       for(int i=0;i<4;i++){
           
           int newx=x+dx[i];
           int newy=y+dy[i];
           
           if(newx>=0 && newx<n && newy>=0 && newy<m && board[newx][newy]=='X'){
               board[newx][newy]='.';
               dfs(board,newx,newy);
               return;
           }
           
       } 
       
       return;
   } 
    
    
    
    
    int countBattleships(vector<vector<char>>& board) {
        
      
        
        int n=board.size();
        int m=board[0].size();
        
        
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    count+=1;
                    dfs(board,i,j);
                }
            }
        }
        
        return count;
    }
};
