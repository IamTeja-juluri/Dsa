#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j,vector<vector<int>>&board,vector<vector<bool>>&visited){
   
   if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]==0 || visited[i][j]==true){
   	return false;
   }
   
   return true;
}

//logic 1

void longestPath(int i,int j,vector<vector<int>>&board,vector<vector<bool>>&visited,int steps,int &ans){
   
   int n=board.size();
   int m=board[0].size();

   if(i==n-1 && j==m-1){
   	ans=max(ans,steps);
   	return;
   }

   visited[i][j]=true;
   
   if(isSafe(i,j+1,board,visited))
   longestPath(i,j+1,board,visited,steps+1,ans);
   if(isSafe(i+1,j,board,visited)) 
   longestPath(i+1,j,board,visited,steps+1,ans);
   if(isSafe(i,j-1,board,visited))
   longestPath(i,j-1,board,visited,steps+1,ans);
   if(isSafe(i-1,j,board,visited))
   longestPath(i-1,j,board,visited,steps+1,ans);
  
   visited[i][j]=false;

}

//logic 2

void longestPath(int i,int j,vector<vector<int>>&board,vector<vector<bool>>&visited,int steps,int &ans){
   
   int n=board.size();
   int m=board[0].size();

   if(i==n-1 && j==m-1){
   	ans=max(ans,steps);
   	return;
   }

   int dx[]={1,-1,0,0};
   int dy[]={0,0,1,-1};

   for(int x=0;x<4;x++){
       
       int newx=i+dx[x];
       int newy=j+dy[x];

       if(isSafe(newx,newy,board,visited)){
       	visited[newx][newy]=true;
       	longestPath(newx,newy,board,visited,steps+1,ans);
        visited[newx][newy]=false;
       }
   }

   return;
}


int main(){

   #ifndef ONLINE_JUDGE
	freopen("inputbl.txt","r",stdin);
	freopen("outputbl.txt","w",stdout);
   #endif
   
   int n,m;
   cin>>n>>m;

   vector<vector<int>>board(n,vector<int>(m,0));
   vector<vector<bool>>visited(n,vector<bool>(m,false));
   
   for(int i=0;i<n;i++){
   	for(int j=0;j<m;j++){
   		int x;
   		cin>>x;
   		board[i][j]=x;
   	}
   }

   int ans=INT_MIN;
   visited[0][0]=true;
   longestPath(0,0,board,visited,1,ans);
   cout<<ans<<endl;	


}