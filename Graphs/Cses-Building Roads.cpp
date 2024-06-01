// Approach 1 using dfs
#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<bool>&visited,vector<int>adj[]){
    visited[i] = true;
    for(auto x:adj[i]){
        if(visited[x] == false){
            dfs(x,visited,adj);
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

    vector<int> adj[n+1];
    vector<bool> visited(n+1,false);
    
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }   
    
    vector<int> resultantRoads;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            resultantRoads.push_back(i);
            dfs(i,visited,adj);
        }
    }
    
    cout<<resultantRoads.size()-1<<endl;
    
    for(int i=1;i<resultantRoads.size();i++){
        cout<<resultantRoads[0]<<" "<<resultantRoads[i]<<endl;
    }
    
    return 0;
}

