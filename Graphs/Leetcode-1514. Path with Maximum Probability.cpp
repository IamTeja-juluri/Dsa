class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dest) {
        
        vector<double> dist(n+1,0.0);
        list<pair<int,double> > *l;
        l=new list<pair<int,double>>[n];
        
       for(int i=0;i<edges.size();i++){
           l[edges[i][0]].push_back({edges[i][1],succProb[i]});
           l[edges[i][1]].push_back({edges[i][0],succProb[i]});
       }
       
        
        priority_queue<pair<double,int> >pq;
        
        dist[src]=1.0;
        pq.push({1.0,src});
        
        while(!pq.empty()){
            
            int node=pq.top().second;
            double nodewt=pq.top().first;
            pq.pop();
            
            for(auto nbrPair:l[node]){
                
                double nbrwt=nbrPair.second;
                int nbr=nbrPair.first;
                
                if(dist[nbr]<(dist[node]*nbrwt)){
                    dist[nbr]=dist[node]*nbrwt;
                    pq.push({dist[nbr],nbr});
                }
            
            }
            
            
        }
        
        return dist[dest];
    }
};
