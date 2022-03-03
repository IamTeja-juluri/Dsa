// without using visited array
#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int> gr[N];

void dfs(int node,int par){

    
    for(auto nbr:gr[node]){

    	if(nbr!=par){
    		dfs(nbr,node);
    	}
    }
  
   
}


int main(){
   
   #ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);
	 freopen("output.txt","w",stdout);
    #endif
	
	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}


   dfs(0,-1);


}