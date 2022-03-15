class Node{
 
 public:

    char data;
    unordered_map<char,Node*>mp;
    bool isTerminal;
    string word;

   Node(char d){
    data=d;
    isTerminal=false;
    word="";
   }

};

class Solution {
public:
      
    
  	Node* root;
    vector<string> res;
    vector<vector<bool>>visited;
    int dx[4],dy[4];
    
     
    Solution(){
      
      root=new Node('\0');
        
      dx[0]=1;
      dx[1]=-1;
      dx[2]=0;
      dx[3]=0;
      dy[0]=0;
      dy[1]=0;
      dy[2]=1;
      dy[3]=-1;

    }
    
    
     void insert(string str){

       Node* temp=root;
       
       for(auto ch:str){
           if(temp->mp.count(ch)==0){
           	Node* newNode=new Node(ch);
           	temp->mp[ch]=newNode;
           }   
           temp=temp->mp[ch];  
       }
       temp->isTerminal=true;
       temp->word=str;
         
    }

   
    void dfs(int x,int y,int n,int m,vector<vector<char>>&board,Node* curr){
      
        char ch=board[x][y];
      
        if(curr->mp.count(ch)==0)
        	return ;
        
        curr=curr->mp[ch];

        if(curr->isTerminal==true){
        	res.push_back(curr->word);
            curr->isTerminal=false;
        }

    	visited[x][y]=true;

      for(int i=0;i<4;i++){

         int newx=x+dx[i];
         int newy=y+dy[i];

         if(newx>=0 && newx<n && newy>=0 && newy<m && visited[newx][newy]==false)
          dfs(newx,newy,n,m,board,curr);
       
      }

      visited[x][y]=false;

    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
     
        int n=board.size();
        int m=board[0].size();
        Node* curr=root;
        visited.resize(n,vector<bool>(m,false));
        
        for(auto x:words)
            insert(x);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(curr->mp.count(board[i][j])!=0)
                 dfs(i,j,n,m,board,curr);
            }
        
        return res;
    }
};
