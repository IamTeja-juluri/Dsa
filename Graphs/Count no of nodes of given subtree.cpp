#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;


void dfs(int node,int par,vector<int> gr[],int count[]){

  count[node]=1;

  for(auto nbr:gr[node]){

  	if(nbr!=par){
     dfs(nbr,node,gr,count);
     count[node]+=count[nbr];
  	}

  }
   

}


int main(){


	#ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output1.txt","w",stdout);
	#endif
     
    int n;
    cin>>n;

    vector<int> gr[n+1];
    int count[n+1]={0};

     for(int i=0;i<n-1;i++){
     	int x,y;
     	cin>>x>>y;
     	gr[x].push_back(y);
     	gr[y].push_back(x);
     }

     dfs(1,0,gr,count);

     for(int i=1;i<=n;i++){
     	cout<<count[i]<<" ";
     }


}