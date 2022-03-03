#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5 + 5;

struct edge{
   int v,weight;
   bool operator<(edge const& other){
    return weight > other.weight;
   }

};

vector<edge> adj[maxn];
int n,m;

int  dijkshatra(){
   
vector<int> dist(n+1,INT_MAX);
vector<bool>processed(n+1,false);

   priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q;

   dist[1]=0;
   q.push({0,1});

       while(!q.empty()){
           
           int node=q.top().second;
           q.pop();

           if(processed[node]){
           	continue;
           }

           processed[node]=true;

           for(auto nbrpair:adj[node]){
             
             int nbr=nbrpair.v;
             int wt=nbrpair.weight;

             if(dist[nbr]==INT_MAX){
              dist[nbr]=dist[node]+wt;
              q.push({dist[nbr],nbr});
             }

             else if(dist[node]+wt > dist[nbr]){
             	dist[nbr]=dist[node]+wt;
             	q.push({dist[nbr],nbr});

             }

           }

       }
       return dist[n];

}


signed main(){

     #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
     #endif 

    cin>>n>>m;
   
    while(m--){

       int x,y,wt;
       cin>>x>>y>>wt;
       
       adj[x].push_back({y,wt});

    }

    int dist=dijkshatra();

    cout<<dist<<endl;

}