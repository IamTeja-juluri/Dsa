#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int n,m,col=0;
vector<int> gr[maxn],rg[maxn];
vector<int> order;
 vector<bool> visited(maxn,false);

int component[maxn];

void topodfs(int node){
	visited[node]=true;

	for(auto nbr:gr[node]){
		if(!visited[nbr]){
			topodfs(nbr);
		}
	}

	order.push_back(node);
}

void dfs(int node){
   
   visited[node]=true;
   component[node]=(col);

   for(auto nbr:rg[node]){

   	if(!visited[nbr]){
   		dfs(nbr);
   	}

   }

}


int main(){

	#ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
	#endif
   
   cin>>n>>m;

   for(int i=0;i<m;i++){
   	 int x,y;
   	 cin>>x>>y;
   	 rg[y].push_back(x);
   	 gr[x].push_back(y);
   }

  visited.assign(n,false);

  for(int i=1;i<=n;i++){

  	if(!visited[i]){
  		topodfs(i);
  	}

  }

  reverse(order.begin(),order.end());

  visited.assign(n,false);

  for(auto x:order){
      
      if(!visited[x]){
      	col+=1;
      	dfs(x);
      }

  }

  cout<<col<<endl;
 
  for(int i=1;i<=n;i++){
  	cout<<component[i]<<" ";
  }
  
  cout<<endl;

}