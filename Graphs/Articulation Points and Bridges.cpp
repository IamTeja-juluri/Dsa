#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int> gr[N];

int visited[N]={0},disc[N]={0},low[N]={0},tme=1;
vector<pair<int,int> > bridges;
set<int> articulation_points;
void dfs(int node,int par){

	visited[node]=1;
    disc[node]=low[node]=tme;
    tme+=1;
    int child=0;

    for(auto nbr:gr[node]){
    	if(!visited[nbr]){
    		dfs(nbr,node);
    		child+=1;
    		//we know low and disc of x
    		low[node]=min(low[node],low[nbr]);
    		//bridges
            
            if(low[nbr] > disc[node]){
               bridges.push_back({node,nbr});
            } 

            //articulation points

            if( par!=0 && low[nbr] >= disc[node]){
             articulation_points.insert(node);
            }

    	}
    	else if(nbr!=par){
            //backedge

            low[node]=min(low[node],disc[nbr]);

    	}
    }

  //check if root is an articulation pt

    if(par==0 && child>1){
    	articulation_points.insert(node);
    }

    return;

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

   dfs(1,0);
   
   //articulation pts
   for(auto x:articulation_points) cout<<x<<" ";
   
   cout<<"Bridges"<<endl;

   //bridges
   for(auto x:bridges){
   	cout<<x.first<<" "<<x.second<<endl; 
   }
   
   

}