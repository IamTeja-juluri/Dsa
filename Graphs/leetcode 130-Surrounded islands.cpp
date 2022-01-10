class Solution {
public:
    
    
    void dfs(int x,int y,vector<vector<char>>& board,vector<vector<bool> > &visited){
        
         int n=board.size();
        int m=board[0].size();
        
        visited[x][y]=true;
        board[x][y]='#';
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        for(int i=0;i<4;i++){
            
            int newx=x+dx[i];
            int newy=y+dy[i];
            
            if(newx>=0 && newx<n && newy>=0 && newy<m && (!visited[newx][newy]) && board[newx][newy]=='O'){
                dfs(newx,newy,board,visited);
            }
            
        }
        
        
    }
    
    
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<bool> > visited;
        
        for(int i=0;i<n;i++){
            vector<bool> v;
            for(int j=0;j<m;j++){
                v.push_back(false);
            }
            visited.push_back(v);
        }
        
        
        
        for(int i=0;i<m;i++){
            
            if( (!visited[0][i]) && (board[0][i]=='O') ){
                dfs(0,i,board,visited);
            }
            if( (!visited[n-1][i]) && (board[n-1][i]=='O') ){
                dfs(n-1,i,board,visited);
            }
            
 
        }
        
        for(int i=0;i<n;i++){
            
            if( (!visited[i][0]) && (board[i][0]=='O') ){
                dfs(i,0,board,visited);
            }
              if( (!visited[i][m-1]) && (board[i][m-1]=='O') ){
                dfs(i,m-1,board,visited);
            }
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
        
      
        
    }
};
