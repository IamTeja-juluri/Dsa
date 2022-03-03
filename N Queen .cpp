#include<bits/stdc++.h>
using namespace std;

bool isValid(int l,int r,vector<vector<int> > &board){
   
    int i=0,j;
    int nc=board[0].size();

//column
    while(i<=l){
        
        if(board[i][r]==1){
        	return false;
        }
        i+=1;
    }

//left diagonal
    i=l,j=r;

    while(i>=0 && j>=0){
    	if(board[i][j]==1){
    		return false;
    	}
    	i-=1;
    	j-=1;
    }

   // right diagonal
    i=l,j=r;

   while(i>=0 && j<nc){
        if(board[i][j]==1){
    		return false;
    	}
    	i-=1;
    	j+=1;   
   }
    
   return true;
}

void printboard(vector<vector<int> > &board){

	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[0].size();j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool Nqueen(int i,vector<vector<int> > &board){
   
   if(i==board.size()){
   	  printboard(board);
   	  return true;
   }


   for(int j=0;j<board[0].size();j++){
     
      if(isValid(i,j,board)){
      	board[i][j]=1;
      	bool success=Nqueen(i+1,board);
      	if(success){
      		return true;
      	}
      	board[i][j]=0;
      }

   }

   return false;

}




int main(){

   #ifndef ONLINE_JUDGE
	freopen("inputb.txt","r",stdin);
	freopen("outputb.txt","w",stdout);
   #endif

   int n;
   cin>>n;
   vector<vector<int> > board(6,vector<int>(6,0));

   cout<<Nqueen(0,board);

}