#include<bits/stdc++.h>
using namespace std;
 
 int v;
 vector<int>gr[100001];
 bool isbipartite;
 vector<bool>visited;
 vector<int>color;
 
 void buildingteams(int src,int clr){
     
     queue<int>q;
     q.push(src);
     visited[src]=true;
     color[src]=clr;
     
     while(!q.empty()){
         int node=q.front();
         q.pop();
         clr=!color[node];
         for(auto nbr:gr[node]){
             if(!visited[nbr]){
                 color[nbr]=clr;
                 visited[nbr]=true;
                 q.push(nbr);
             }
             else if(color[nbr]!=clr){
                 isbipartite=false;
                 return;
             }
         }
     }
     
 }
    
    
int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("inputgr.txt","r",stdin);
    freopen("outputgr.txt","w",stdout);
    #endif
    
    int n,m;
    cin>>n>>m;
    
    v=n;
    
    for(int i=0;i<m;i++){   
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    
    isbipartite=true;
    visited.resize(n+1,false);
    color.resize(n+1,0);
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            buildingteams(i,0);
        }
    }
    
    if(isbipartite){
        for(int i=1;i<=n;i++)
        cout<<color[i]+1<<" ";
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    
}
