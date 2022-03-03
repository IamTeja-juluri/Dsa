//Recursive
#include<bits/stdc++.h>
using namespace std;

int combinations(int n){
    
    if(n<0){
    	return 0;
    }
   
    if(n==0){
    	return 1;
    }

   return combinations(n-1)+combinations(n-2)+combinations(n-3)+combinations(n-4)+combinations(n-5)+combinations(n-6);
    
}


int main(){

	#ifndef ONLINE_JUDGE
	   freopen("input.txt","r",stdin);
	   freopen("output.txt","w",stdout);
	#endif
	  
	  int n;
	  cin>>n;

     cout<<combinations(n)<<endl;
    

	}