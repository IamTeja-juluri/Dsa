#include<bits/stdc++.h>
using namespace std;


bool isValid(int l,int r,vector<vector<int>>&board){
  
  int i=0,j;
  
  while(i<=l){
  	if(board[i][r]==1){
     return false;
  	}
  	i+=1;
  }

 i=l,j=r;

 while(i>=0 && j>=0){
    if(board[i][j]==1){
    	return false;
    }
   i-=1;
   j-=1;
 }

 i=l,j=r;

 while(i>=0 && j<board[0].size()){
     if(board[i][j]==1){
     	return false;
     }
     i-=1;
     j+=1;
 }
  
  return true;
 

}

int NqueenWays(vector<vector<int> > &board,int i){

 if(i==board.size()){
   
   return 1;
 }

  int ways=0;

   for(int j=0;j<board[0].size();j++){

   	  if(isValid(i,j,board)){
   	  	board[i][j]=1;
   	  	ways+=NqueenWays(board,i+1);
   	  	board[i][j]=0;
   	  }
   }
 
 return ways;

}

int main(){
   
   #ifndef ONLINE_JUDGE
	freopen("inputb.txt","r",stdin);
	freopen("outputb.txt","w",stdout);
   #endif

   vector<vector<int> > board(8,vector<int>(8,0));

   cout<<NqueenWays(board,0)<<endl;
   
}