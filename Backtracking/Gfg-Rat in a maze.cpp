
class Solution{
    public:
    
    bool isSafe(int i,int j,vector<vector<int>>&board,vector<vector<bool>>&visited){
        
        int n=board.size();
        
        if(i<0 || i>=n || j<0 || j>=n || visited[i][j]==true || board[i][j]==0){
            return false;
        }
        return true;
    }
    
    void backTrack(int i,int j,vector<vector<int>>&board,vector<vector<bool>>&visited,string ans,vector<string>&res){
        
        int n=board.size();
        
        if(i==n-1 && j==n-1){
            res.push_back(ans);
            return ;
        }
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        char dir[]={'R','D','L','U'};
        
        for(int z=0;z<4;z++){
            
            int x=i+dx[z];
            int y=j+dy[z];
            char ch=dir[z];
            
            if(isSafe(x,y,board,visited)){
                
                visited[x][y]=true;
                backTrack(x,y,board,visited,ans+ch,res);
                visited[x][y]=false;
            }
            
        }
        
        return ;
    }
    
    
    
    vector<string> findPath(vector<vector<int>> &board, int n) {
       
       vector<string> res;
       if(board[0][0]==0){
           return res;
       }
       vector<vector<bool>>visited(n,vector<bool>(n,false));
       visited[0][0]=true;
       backTrack(0,0,board,visited,"",res);
       return res;
    }
};