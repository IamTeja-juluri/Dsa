class Solution {
public:
    
    int countPaths(int n, vector<vector<int>>& roads) {

        int mod=1e9+7;
        vector<pair<long long,long long>>l[n];
        
        for(auto x:roads){
            long long f=x[0];
            long long s=x[1];
            long long w=x[2];
            l[f].push_back({s,w});
            l[s].push_back({f,w});
        }
        
        set<pair<long long,long long>>s;
        vector<long long>dist(n,LONG_MAX);
        vector<long long>ways(n,0);
        s.insert({0,0});
        dist[0]=0;
        ways[0]=1;
        
        while(!s.empty()){
            
            auto it=s.begin();
            long long node=it->second;
            long long nodeweight=it->first;
            s.erase(it);
            
            for(auto nbrPair:l[node]){
                
                long long nbr=nbrPair.first;
                long long nbrwt=nbrPair.second;
                if(nodeweight+nbrwt<dist[nbr]){
                    
                    auto f=s.find({dist[nbr],nbr});
                     if(f!=s.end())
                     s.erase(f);
                    
                    dist[nbr]=nodeweight+nbrwt;
                    ways[nbr]=ways[node];
                    s.insert({dist[nbr],nbr});
                }
                else if(nodeweight+nbrwt==dist[nbr])
                    ways[nbr]=(ways[node]+ways[nbr])%mod;
            }
            
        }
        
        return ways[n-1];
    }
};
