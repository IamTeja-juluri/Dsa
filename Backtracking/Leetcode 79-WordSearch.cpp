// Soln 1 using visited
class Solution {
public:
    
  
   bool dfs(int i,int j,int k,vector<vector<char>>&board,string word,vector<vector<int>>&visited){
       
       if(k==word.size()){
           return true;
       }
       
       if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j]!=0 || word[k]!=board[i][j]){
           return false;
       }
       
      
       visited[i][j]=1;
       
       bool res=dfs(i+1,j,k+1,board,word,visited) ||  dfs(i-1,j,k+1,board,word,visited) ||   dfs(i,j+1,k+1,board,word,visited) || dfs(i,j-1,k+1,board,word,visited);
       
       visited[i][j]=0;
      
       return res;
           
   }

    
    
    bool exist(vector<vector<char>>& board, string word) {
      
        int n=board.size();
        int c=board[0].size();
        int len=word.length();
        
        if( (n*c)<len ) return false;
        
        vector<vector<int>>visited(n,vector<int>(c,0));
        int k=0;
        
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]==word[k]){
                    
                    bool ans=dfs(i,j,k,board,word,visited);
                    if(ans){
                        return true;
                    }
                }
                
            }
            
        }
        
        return false;
        
        
    }
};

//soln 2 

class Solution {
    
public:
  
   bool dfs(int i,int j,int k,vector<vector<char>>&board,string word,vector<vector<int>>&visited){
       
       if(k==word.size()){
           return true;
       }
       
       if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j]!=0 || word[k]!=board[i][j]){
           return false;
       }
       
     int dx[]={1,-1,0,0};
     int dy[]={0,0,1,-1};
      
       visited[i][j]=1;
       
       bool res=false;
       
       for(int z=0;z<4;z++){
           
           int x=i+dx[z];
           int y=j+dy[z];
           res=res||dfs(x,y,k+1,board,word,visited);
           
           
       }
       
       visited[i][j]=0;
      
       return res;
           
   }

    
    
    bool exist(vector<vector<char>>& board, string word) {
      
        int n=board.size();
        int c=board[0].size();
        int len=word.length();
        
        if( (n*c)<len ) return false;
        
        vector<vector<int>>visited(n,vector<int>(c,0));
        int k=0;
        
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]==word[k]){
                    
                    bool ans=dfs(i,j,k,board,word,visited);
                    if(ans){
                        return true;
                    }
                }
                
            }
            
        }
        
        return false;
        
        
    }
};












//Soln 3 without using visited

class Solution {
public:
    
  
   bool dfs(int i,int j,int k,vector<vector<char>>&board,string word){
       
       if(k==word.size()){
           return true;
       }
       
       if(i<0 || i>=board.size() || j<0 || j>=board[0].size()  || word[k]!=board[i][j]){
           return false;
       }
       
       
       char temp=board[i][j];
       board[i][j]='#';
       // visited[i][j]=true;
       
       bool res=dfs(i+1,j,k+1,board,word) ||  dfs(i-1,j,k+1,board,word) ||   dfs(i,j+1,k+1,board,word) || dfs(i,j-1,k+1,board,word);
       
       // visited[i][j]=false;
       board[i][j]=temp;
       return res;
           
   }

    
    
    bool exist(vector<vector<char>>& board, string word) {
      
        int n=board.size();
        int c=board[0].size();
        int len=word.length();
        
        if( (n*c)<len ) return false;
        
        // vector<vector<bool>>visited(n,vector<bool>(n,false));
        int k=0;
        
        for(int i=0;i<board.size();i++){
            
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]==word[k]){
                    
                    bool ans=dfs(i,j,k,board,word);
                    if(ans){
                        return true;
                    }
                }
                
            }
            
        }
        
        return false;
        
        
    }
};
