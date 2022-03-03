#include<bits/stdc++.h>
using namespace std;

int game(int a[],int i,int j){

  if(i>j){
	return 0;
    }
 
  int l=a[i]+game(a,i+1,j);
  int r=a[j]+game(a,i,j-1);

  return max(l,r);

}



int main(){
   
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

   int n;
   cin>>n;

   int a[n];

   for(int i=0;i<n;i++){
   	cin>>a[i];
   }

   cout<<game(a,0,n-1)<<endl;

}