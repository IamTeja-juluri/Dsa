#include<bits/stdc++.h>
using namespace std;
  
  void printboard(vector<vector<int>>&board){

     for(int i=0;i<board.size();i++){
     	for(int j=0;j<board[0].size();j++){
     		cout<<setw(2)<<board[i][j]<<" ";
     	}
     	cout<<endl;
     }

  }

  bool isSafe(int i,int j,vector<vector<int>>&board){

    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=-1){
        return false;
    }
    
    return true;
  }
  

  bool knightsTour(int i,int j,int k,vector<vector<int>>&board){
    
    int n=board.size();
    
    if(k == n*n){
    	printboard(board);
    	return true;
    }
  
  //Give coordinates such that it forms clockwise or anti clockwise cycle to speed up  
  int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
   
	
    for(int z=0;z<8;z++){

    	int x=i+dx[z];
    	int y=j+dy[z];

        if(isSafe(x,y,board)){
            board[x][y]=k;
            bool res=knightsTour(x,y,k+1,board);
            if(res){
                return true;
            }
            board[x][y]=-1;
        }
       
    }
    
    return false;

  }


int main(){

  vector<vector<int>>board(8,vector<int>(8,-1));
  board[0][0]=0;
  cout<<knightsTour(0,0,1,board);

}
