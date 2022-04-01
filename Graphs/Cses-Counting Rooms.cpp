#include<bits/stdc++.h>
using namespace std;
 
 vector<vector<char>>board;
 void dfs(int x,int y){
     if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]=='#')
     return;
     board[x][y]='#';
     dfs(x,y-1);
     dfs(x-1,y);
     dfs(x,y+1);
     dfs(x+1,y);
 }
    
    
int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("inputgr.txt","r",stdin);
    freopen("outputgr.txt","w",stdout);
    #endif
    
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){   
        vector<char>v;
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            v.push_back(x);
        }
        board.push_back(v);
    }
    
    int count=0;

    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(board[i][j]=='.'){
               count+=1;
               dfs(i,j);
           }
       }
    }
    
    cout<<count<<endl;
    
}
