// without using visited array
#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int> gr[N];
int parent[N];

void dfs(int node,int par){
    
    parent[node]=par;
    
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
	
	int n;
	cin>>n;

	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}


   dfs(10,0);

   int x=6;
   

   //find all ancestors
   //Basically find a path from root to given vertex
   //Similarly for path based quesns like given a tree and two nodes x and y print the path
   //we can make x or y as root and print all ancestors

   while(x){
        cout<<x<<" ";
   	    x=parent[x];
   }


}