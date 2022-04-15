#define MOD 1000000007
class Solution
{
    public:
    list<pair<int,int> > *graph;
    int dfs( int u, int n, vector<long long int>& distance, vector<int>& paths)
    {
        if(paths[u]!=-1)
            return paths[u];
        
            paths[u]=0;
            for(auto p:graph[u])
            {
                int v=p.first,w=p.second;
                if(distance[v]<distance[u])
                    paths[u]=(paths[u]+dfs(v,n,distance,paths))%MOD;
            }
        return paths[u];
    }
    void djikstra( int start, vector<long long int>& distance)
    {
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
        
        pq.push({0,start});
        distance[start]=0;
        
        while(!pq.empty())
        {
            long long int du=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            
            for(auto p:graph[u])
            {
                int v=p.first,dv=p.second;
                long long int dist=distance[u]+dv;
                if(dist<distance[v])
                {
                    distance[v]=dist;
                    pq.push({distance[v],v});
                }
            }
        }
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges)
    {
        // unordered_map<int,vector<pair<int,int>>>graph;
        graph=new list<pair<int,int> > [n+1];
        
        for(auto edge:edges)
        {
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
        
        vector<long long int>distance(n+1,LLONG_MAX);
        djikstra(n,distance);

        vector<int>paths(n+1,-1);
        paths[n]=1;
        dfs(1,n,distance,paths);
        
        return paths[1];
    }
};
