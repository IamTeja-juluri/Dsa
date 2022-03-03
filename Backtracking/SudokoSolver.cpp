#include<bits/stdc++.h>
using namespace std;

void printboard(vector<vector<int>>&board){

	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[0].size();j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool isValid(int l,int r,int k,vector<vector<int>>&board){
   
   int i=0,j=0;

//Along row
   while(j<board[0].size()){
        
        if(board[l][j]==k){
        	return false;
        }
        j+=1;

   }

//Along col

  while(i<board.size()){
  	   if(board[i][r]==k){
  	   	return false;
  	   }
  	   i+=1;
  }  

  int spx=(l/3)*3;
  int spy=(r/3)*3;

  for(int i=spx;i<spx+3;i++){
    
    for(int j=spy;j<spy+3;j++){

    	if(board[i][j]==k){
    		return false;
    	}
    }

  }


 return true;

}


bool sudokosolver(int i,int j,vector<vector<int>>&board){
   

     if(j==board[0].size()){

        if(i==board.size()-1){
        	printboard(board);
        	return true;
        }

        i=i+1;
        j=0;

      }
  
     if(board[i][j]!=0){
     	return sudokosolver(i,j+1,board);
     }

  for(int k=1;k<=9;k++){

      if(isValid(i,j,k,board)){

        board[i][j]=k;

      	bool res=sudokosolver(i,j+1,board);

      	if(res)
      	  return true;
        	
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

   vector<vector<int> > board(9,vector<int>(9,0));


   for(int i=0;i<9;i++){
   	for(int j=0;j<9;j++){
   		int x;
   		cin>>x;
   		board[i][j]=x;
   	}
   }

 
  cout<<sudokosolver(0,0,board);


}